#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define SIZE 100000
#define MAX_DEPTH 4 // ~16 thread aktif

// Struct diperlukan karena pthread_create hanya menerima satu parameter void*
struct SortArgs {
    int *arr;
    int low;
    int high;
    int depth;
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
    int depth = args->depth;

    if (low < high) {
        int pi = partition(arr, low, high);

        // Jika kedalaman belum mencapai limit, gunakan Multithreading
        if (depth < MAX_DEPTH) {
            struct SortArgs leftArgs = {arr, low, pi - 1, depth + 1};
            struct SortArgs rightArgs = {arr, pi + 1, high, depth + 1};

            pthread_t leftThread;
            if (pthread_create(&leftThread, NULL, quickSort, &leftArgs) == 0) {
                // Sisi kanan dikerjakan thread saat ini secara rekursif
                quickSort(&rightArgs);
                // Menunggu thread pendamping selesai sebelum naik ke level rekursi diatas
                pthread_join(leftThread, NULL);
            } else {
                // Fallback jika pthread_create gagal
                quickSort(&leftArgs);
                quickSort(&rightArgs);
            }
        } 
        // Jika sudah mencapai limit, gunakan Rekursi Sekuensial biasa
        else {
            struct SortArgs leftArgs = {arr, low, pi - 1, depth + 1};
            struct SortArgs rightArgs = {arr, pi + 1, high, depth + 1};
            
            quickSort(&leftArgs);
            quickSort(&rightArgs);
        }
    }
    return NULL;
}

int main() {
    // Menggunakan malloc biasa karena thread berada di dalam satu virtual address space yang sama
    int *data = malloc(SIZE * sizeof(int));
    srand(time(NULL));

    for (int i = 0; i < SIZE; i++) data[i] = rand() % 100000;

    struct SortArgs args = {data, 0, SIZE - 1, 0};

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
