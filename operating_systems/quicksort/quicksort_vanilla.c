#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

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

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int *data = malloc(SIZE * sizeof(int));
    srand(time(NULL));

    for (int i = 0; i < SIZE; i++) {
        data[i] = rand() % 100000;
    }

    printf("Menyortir %d elemen dengan rekursif...\n", SIZE);
    clock_t start = clock();

    quickSort(data, 0, SIZE - 1);

    clock_t end = clock();
    double time_taken = ((double)end - start) / CLOCKS_PER_SEC;

    printf("Selesai! Waktu: %f sekon\n", time_taken);

    for(int i=0; i<100; i++) printf("%d ", data[i]);
    printf("...\n");

    printf("Data ter generate dengan sukses.\n");
    free(data);
    return 0;
}
