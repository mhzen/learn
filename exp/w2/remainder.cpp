#include <iostream>

using namespace std;

main() {
    int hargaPensil = 2500, hargaBuku = 5000, jumlahUang, jumlahPensil, jumlahBuku, sisaUang;

    cout << "Masukkan Jumlah Uang: Rp";
    cin >> jumlahUang;
    cout << "Masukkan Jumlah Pensil: ";
    cin >> jumlahPensil;
    cout << "Masukkan Jumlah Buku: ";
    cin >> jumlahBuku;

    sisaUang = jumlahUang - (hargaPensil * jumlahPensil + hargaBuku * jumlahBuku);
    cout << "Sisa Uang: Rp" << sisaUang << endl;
}