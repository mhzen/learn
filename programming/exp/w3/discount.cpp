#include<iostream>
using namespace std;

int main(){
    int harga, diskon;
    cout<<"Masukkan total belanja = ";
    cin>>harga;

    if (harga > 500000){
        diskon = 20;
    }else if(harga >= 300000){
        diskon = 10;
    }else if(harga >= 100000){
        diskon = 5;
    }else{
        diskon = 0;
    }

    cout<<"Mendapat diskon "<<diskon<<"%"<<endl;

    return 0;
}
