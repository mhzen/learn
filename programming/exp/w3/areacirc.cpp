#include<iostream>
using namespace std;

int main(){
    int panjang, lebar, luas, keliling;

    cout<<"Masukkan panjang (dalam m) = ";
    cin>>panjang;
    cout<<"Masukkan lebar (dalam m) = ";
    cin>>lebar;

    cout<<"Keliling persegi = "<<2*(panjang+lebar)<<endl;
    cout<<"Luas persegi = "<<panjang*lebar<<endl;
    return 0;
}