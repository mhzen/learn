#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <time.h>

#define SIZE 100000
#define THRESHOLD 10000 // Higher threshold for processes because fork() is heavy

void swap(int* a, int* b) { int t = *a; *a = *b; *b = t; }

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort_process(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // We only fork if the work is big enough to justify the overhead
        if (high - low > THRESHOLD) {
            pid_t pid = fork();

            if (pid < 0) {
                perror("Fork failed");
                exit(1);
            } else if (pid == 0) {
                // Child process handles the left side
                quicksort_process(arr, low, pi - 1);
                exit(0); // Child must exit so it doesn't return to main()
            } else {
                // Parent process handles the right side
                quicksort_process(arr, pi + 1, high);
                // Parent waits for the child to finish its half
                wait(NULL); 
            }
        } else {
            // Sequential recursion for smaller chunks
            quicksort_process(arr, low, pi - 1);
            quicksort_process(arr, pi + 1, high);
        }
    }
}

int main() {
    // Step 1: Create Shared Memory
    int *data = mmap(NULL, SIZE * sizeof(int), PROT_READ | PROT_WRITE, 
                     MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    if (data == MAP_FAILED) {
        perror("mmap failed");
        return 1;
    }

    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) data[i] = rand() % 100000;

    printf("Sorting %d elements with Multiprogramming (fork)...\n", SIZE);

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    quicksort_process(data, 0, SIZE - 1);

    clock_gettime(CLOCK_MONOTONIC, &end);
    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    printf("Finished! Wall time: %f seconds\n", time_taken);
    printf("First 5: %d %d %d %d %d\n", data[0], data[1], data[2], data[3], data[4]);

    // Cleanup
    munmap(data, SIZE * sizeof(int));
    return 0;
}
