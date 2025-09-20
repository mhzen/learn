#include<iostream>
using namespace std;

int main(){
    int angka;
    cout<<"Masukkan bilangan = ";
    cin>>angka;

    if(angka % 2 == 0){
        cout<<angka<<" merupakan bilangan genap"<<endl;
    }else{
        cout<<angka<<" merupakan bilangan ganjil"<<endl;
    }
    return 0;
}