#include <iostream>
using namespace std;

// Fungsi bantu: tukar nilai dua variabel (menggunakan pass by reference)
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Pengurutan bubble sort
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Pencarian biner dengan langkah tambahan:
// 1) Urutkan data terlebih dahulu (karena binary search membutuhkan data terurut).
// 2) Lakukan binary search untuk menemukan satu indeks yang cocok.
// 3) Setelah ditemukan, periksa ke kiri/kanan untuk menemukan semua kemunculan
//    (menentukan indeks pertama dan terakhir) sehingga bisa menampilkan
//    semua indeks dan jumlah kemunculan.
void binSearch(int arr[], int size, int target)
{
    bubbleSort(arr, size);

    cout << "Data Terurut: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    int left = 0;
    int right = size - 1;
    int ditemukan = -1;

    // Algoritma binary search
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            ditemukan = mid;
            break;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if (ditemukan == -1)
    {
        cout << endl;
        cout << "Tidak ditemukan";
        return;
    }

    // Temukan indeks pertama dan terakhir dari target
    int first = ditemukan;
    int last = ditemukan;
    // Periksa ke kiri untuk indeks pertama
    while (first - 1 >= 0 && arr[first - 1] == target)
        first--;
    // Periksa ke kanan untuk indeks terakhir
    while (last + 1 < size && arr[last + 1] == target)
        last++;

    cout << endl;
    cout << "Ditemukan di indeks ";
    // Tampilkan semua indeks dari first ke last
    for (int k = first; k <= last; ++k)
    {
        cout << k;
        if (k < last)
            cout << ", ";
    }
    cout << endl;
    cout << "Data ditemukan " << (last - first + 1) << " kali";
}

int main()
{
    int jumlah;
    cout << "Jumlah data: ";
    cin >> jumlah;
    int data[jumlah] = {0};

    for (int i = 0; i < jumlah; i++)
    {
        cin >> data[i];
    }

    cout << "Target: ";
    int target;
    cin >> target;

    binSearch(data, jumlah, target);
}