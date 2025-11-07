#include<iostream>
#include<iomanip>
using namespace std;

int totalHadir = 0;

void tambahHadir(int hadir){
    totalHadir += hadir;
}

float rasioHadir(int totalKehadiranMaks){
    // https://www.geeksforgeeks.org/cpp/static_cast-in-cpp/
    return ((static_cast<float>(totalHadir) / totalKehadiranMaks) * 100);
}

void tampilkanHasil(int totalKehadiranMaks){
    cout<<"Total kehadiran kelas: "<< totalHadir << " dari " << totalKehadiranMaks << endl;
    cout<<"Persentase kehadiran: "<<fixed<<setprecision(2)<<rasioHadir(totalKehadiranMaks)<<"%"<<endl;
}

int main(){
    int n, j;
    cout<<"Masukkan jumlah siswa: ";
    cin>>n;
    cout<<"Masukkan jumlah pertemuan: ";
    cin>>j;
    for (int i=0; i<n; i++){
        int hadir;
        cout<<"Kehadiran mahasiswa ke-"<<i+1 <<": ";
        cin>>hadir;
        tambahHadir(hadir);
    }
    tampilkanHasil(n * j);
}