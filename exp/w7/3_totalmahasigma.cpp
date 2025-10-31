#include<iostream>
#include<iomanip>
using namespace std;

int totalHadir = 0;

void tambahHadir(int hadir)
{
    totalHadir += hadir;
}

float rasioHadir(int totalSiswa)
{
    // type conversion: https://www.learncpp.com/cpp-tutorial/introduction-to-type-conversion-and-static_cast/
    return (static_cast<float>(totalHadir) / totalSiswa) * 100;
}

void tampilkanHadir(int totalSiswa)
{
    cout << "Total kehadiran kelas: " << totalHadir << " dari " << totalSiswa << endl;
    cout << "Persentase kehadiran: " << fixed << setprecision(2) << rasioHadir(totalSiswa) << "%" << endl;
}

int main()
{
    int n, i;
    cout << "Masukkan jumlah siswa: ";
    cin >> n;
    cout << "Masukkan jumlah pertemuan: ";
    cin >> i;
    if (n <= 0 || i <= 0) return 1;
    for (int i = 0; i < n; i++)
    {
        int hadir;
        cout << "Masukkan kehadiran siswa ke-" << i + 1 << ": ";
        cin >> hadir;
        tambahHadir(hadir);
    }
    tampilkanHadir(n * i);
    return 0;
}