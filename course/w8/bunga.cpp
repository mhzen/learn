#include<iostream>
using namespace std;

float jumlah(float uang, int bulan, float bunga){
    if ( bulan % 12 != 0){
        bulan = bulan - ( bulan % 12);
    }
    float total = uang + (uang*(bunga/100)*(bulan/12));
    return total;
}

int main(){
    float x, z, a;
    int y;
    cout<<"Masukkan Uang, Bulan, dan Bunga (dalam persen, tanpa %):"<<endl;
    cin>>x>>y>>z;
    a = jumlah(x, y, z);
    cout<<a;
    return 0;
}