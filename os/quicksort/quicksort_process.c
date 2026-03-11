#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <time.h>

#define SIZE 100000
#define MAX_DEPTH 4

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

void quickSort(int arr[], int low, int high, int depth) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Jika kedalaman belum mencapai batas, gunakan Multiprocessing
        if (depth < MAX_DEPTH) {
            pid_t pid = fork();

            if (pid < 0) {
                // Jika fork gagal, otomatis jalankan sekuensial untuk bagian ini
                quickSort(arr, low, pi - 1, MAX_DEPTH); 
                quickSort(arr, pi + 1, high, MAX_DEPTH);
            } else if (pid == 0) {
                // Child Process: Mengerjakan sisi kiri
                quickSort(arr, low, pi - 1, depth + 1);
                exit(0); 
            } else {
                // Parent Process: Mengerjakan sisi kanan
                quickSort(arr, pi + 1, high, depth + 1);
                wait(NULL); // Tunggu child selesai agar data konsisten
            }
        } 
        // Jika sudah mencapai MAX_DEPTH, jalankan Rekursi Biasa (Sekuensial)
        else {
            quickSort(arr, low, pi - 1, depth + 1);
            quickSort(arr, pi + 1, high, depth + 1);
        }
    }
}

int main() {
    // mmap: Membuat shared memory. Penting karena proses memiliki memori terisolasi.
    // Tanpa MAP_SHARED, hasil pengurutan child process tidak akan tersimpan di array utama.
    int *data = mmap(NULL, SIZE * sizeof(int), PROT_READ | PROT_WRITE, 
                     MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    if (data == MAP_FAILED) {
        perror("mmap failed");
        return 1;
    }

    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) data[i] = rand() % 100000;

    printf("Menyortir %d elemen dengan multiprogramming...\n", SIZE);

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    quickSort(data, 0, SIZE - 1, 0);

    clock_gettime(CLOCK_MONOTONIC, &end);

    printf("Selesai! Waktu: %f sekon\n", (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9);

    for(int i=0; i<100; i++) printf("%d ", data[i]);
    printf("...\n");

    printf("Data ter generate dengan sukses.\n");

    munmap(data, SIZE * sizeof(int));
    return 0;
}
