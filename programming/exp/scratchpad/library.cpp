#include<iostream>
#include<string>
using namespace std;

struct Buku {
    string judul;
    int kode;
    int tahun;
};

// void swap(int &kiri, int &kanan){
//     int temp = kiri;
//     kiri = kanan;
//     kanan = temp;
// }

int main(){
    int n;
    cout<<"Masukkan jumlah buku: ";
    cin>>n;
    cin.ignore();
    Buku buku[n];
    for (int i = 0; i<n; i++){
        cout<<"--------------------"<<endl;
        cout<<"Buku "<<i+1<<", "<<endl;
        cout<<"Nama: ";
        getline(cin, buku[i].judul);
        cout<<"Kode: ";
        cin>>buku[i].kode;
        cout<<"Tahun: ";
        cin>>buku[i].tahun;
        cin.ignore();
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - 1 - i; j++){
            if (buku[j].kode > buku[j+1].kode){
                swap(buku[j], buku[j+1]);
            }
        }
    }
    cout<<"--------------------"<<endl;
    cout<<"Masukkan kode buku dicari: ";
    int k;
    cin>>k;
    cout<<"--------------------"<<endl;
    int l=0;
    int r=n-1;
    bool ada=0;
    while(l<=r){
        int m=(l+r)/2;
        if (buku[m].kode == k){
            ada=1;
            cout << "Buku Ditemukan"<< endl
                 << "Judul: " << buku[m].judul << endl
                 << "Tahun: " << buku[m].tahun << endl;
            break;
        }else if (buku[m].kode < k){
            l = m+1;
        }else if (buku[m].kode > k){
            r = m-1;
        }
    }
    if (!ada){
        cout << "Buku tidak ditemukan";
    }
}