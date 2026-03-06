#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define SIZE 100000
#define THRESHOLD 10000 // Only create threads for chunks larger than this

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

void* quickSort(void* arg) {
    struct SortArgs* args = (struct SortArgs*)arg;
    int low = args->low;
    int high = args->high;
    int* arr = args->arr;

    if (low < high) {
        int pi = partition(arr, low, high);

        struct SortArgs leftArgs = {arr, low, pi - 1};
        struct SortArgs rightArgs = {arr, pi + 1, high};

        if ((high - low) > THRESHOLD) {
            pthread_t leftThread;
            pthread_create(&leftThread, NULL, quickSort, &leftArgs);
     
            quickSort(&rightArgs);

            pthread_join(leftThread, NULL);
        } else {
            quickSort(&leftArgs);
            quickSort(&rightArgs);
        }
    }
    return NULL;
}

int main() {
    int *data = malloc(SIZE * sizeof(int));
    srand(time(NULL));

    for (int i = 0; i < SIZE; i++) data[i] = rand() % 100000;

    struct SortArgs args = {data, 0, SIZE - 1};

    printf("Menyortir %d elemen dengan threads...\n", SIZE);

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    quickSort(&args);

    clock_gettime(CLOCK_MONOTONIC, &end);

    printf("Selesai! Waktu: %f sekon\n", (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9);

    for(int i=0; i<100; i++) printf("%d ", data[i]);
    printf("...\n");

    printf("Data ter generate dengan sukses.\n");

    free(data);
    return 0;
}
