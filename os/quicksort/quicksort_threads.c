#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define THRESHOLD 1000 // Only create threads for chunks larger than this

struct SortArgs {
    int *arr;
    int low;
    int high;
};

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

void* threaded_quickSort(void* arg) {
    struct SortArgs* args = (struct SortArgs*)arg;
    int low = args->low;
    int high = args->high;
    int* arr = args->arr;

    if (low < high) {
        int pi = partition(arr, low, high);

        struct SortArgs leftArgs = {arr, low, pi - 1};
        struct SortArgs rightArgs = {arr, pi + 1, high};

        // If the task is big enough, spawn a thread for the left side
        if ((high - low) > THRESHOLD) {
            pthread_t leftThread;
            pthread_create(&leftThread, NULL, threaded_quickSort, &leftArgs);

            // Current thread handles the right side
            threaded_quickSort(&rightArgs);

            // Wait for the worker thread to finish
            pthread_join(leftThread, NULL);
        } else {
            // If the task is small, just do it sequentially (no new thread)
            threaded_quickSort(&leftArgs);
            threaded_quickSort(&rightArgs);
        }
    }
    return NULL;
}

int main() {
    int n = 100000;
    int *data = malloc(n * sizeof(int));
    srand(time(NULL));

    for (int i = 0; i < n; i++) data[i] = rand() % 100000;

    struct SortArgs args = {data, 0, n - 1};

    printf("Sorting %d elements with threads...\n", n);

    clock_t start = clock();
    threaded_quickSort(&args);
    clock_t end = clock();

    printf("Done! Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Print first 10 to verify
    for(int i=0; i<100; i++) printf("%d ", data[i]);
    printf("\n");

    free(data);
    return 0;
}
