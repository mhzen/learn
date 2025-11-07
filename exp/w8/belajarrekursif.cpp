#include <iostream>
#include <fstream> // Diperlukan untuk membaca file
using namespace std;

int bacadata(int arr[])
{
    ifstream file("angka_input.txt"); // Membuka file

    // Cek apakah file berhasil dibuka
    if (!file.is_open())
    {
        cout << "Error: Gagal membuka file angka_input.txt!" << endl;
        return 0; // Kembalikan 0 jika gagal
    }

    int angka;
    int hitungan = 0; // Untuk menghitung jumlah angka yang dibaca

    // Membaca file angka per angka sampai akhir file
    while (file >> angka)
    {
        arr[hitungan] = angka; // Simpan angka ke dalam array
        hitungan++;            // Tambah hitungan
    }

    file.close();    // Tutup file setelah selesai
    return hitungan; // Kembalikan jumlah elemen yang dibaca
}

int maksimumRekursif(int arr[], int n)
{
    // Basis kasus: Jika array hanya punya 1 elemen, elemen itu adalah maks
    if (n == 1)
        return arr[0];

    // Langkah rekursif: Cari nilai maksimum dari (n-1) elemen pertama
    int maxSubarray = maksimumRekursif(arr, n - 1);

    // Bandingkan hasil rekursif dengan elemen terakhir (arr[n-1])
    return (arr[n - 1] > maxSubarray) ? arr[n - 1] : maxSubarray;
}

int main()
{
    // Siapkan array dengan ukuran yang cukup besar
    // Kita asumsikan file tidak akan berisi lebih dari 100 angka
    int arr[100];

    // Panggil bacadata() untuk mengisi array dan mendapatkan jumlah elemen (n)
    // Ini menggantikan bagian '<bacadata>' dan 'n = sizeof...'
    int n = bacadata(arr);

    // Cek jika ada data yang berhasil dibaca
    if (n == 0)
    {
        cout << "Tidak ada data yang dapat diproses." << endl;
    }

    // Panggil fungsi rekursif untuk mencari nilai maksimum
    cout << "Nilai maksimum dalam array: " << maksimumRekursif(arr, n) << endl;

    return 0;
}