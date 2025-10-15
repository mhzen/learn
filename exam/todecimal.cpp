// Buatlah algoritma (pseudocode/flowchart) untuk mengkonversi bilangan desimal N menjadi bilangan biner.
// Sebagai contoh masukan algoritma adalah bilangan N=35 maka keluarannya adalah string 100011.
// Karena 100011 dalam desimal nilainya adalah 1*2^5 + 1*2^1 + 1*2^0 = 35.
#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    string m = "";
    cin>>n;
    if (n==0){
        m = "0";
    }else{
        while (n>0){
           int left = n % 2;
           m = to_string(left) + m;
           n = n / 2;
        }
    }
    cout<<m<<endl;
    // oops reversed haha
    // string n;
    // cin>>n;
    // int l = n.length();
    // int m = 0;
    // for (int i=0; i<l; i++){
    //     if (n[i] == '1'){
    //         m = m + pow(2, (l-i-1));
    //     }
    // }
    // cout<<m<<endl;
}