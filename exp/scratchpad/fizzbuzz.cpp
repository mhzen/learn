#include<iostream>
using namespace std;

void cek(int n){
    for (int i = 1; i <= n; i++){
        if (i % 3 == 0 && i % 5 == 0){
            cout<<"TigaLima";
        }else if (i % 3 == 0){
            cout<<"Tiga";
        }else if (i % 5 == 0){
            cout<<"Lima";
        }else{
            cout<<i;
        }
        cout<<" ";
    }
}

int main(){
    int n;
    cout<<"Masukkan N: ";
    cin>>n;
    cek(n);
}