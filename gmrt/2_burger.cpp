#include<bits/stdc++.h>
using namespace std;

// Program ini mengikuti logika di CONTOH dimana burger ayam membutuhkan 2 Roti DAN 1 Daging Ayam (Diasumsikan dari hasil)
// Berbeda dengan di SOAL dimana burger ayam membutuhkan 2 Roti DAN 2 Daging Ayam

int main(){
    int r, s, a, p, q;
    cin>>r>>s>>a>>p>>q;
    int k=0;
    if (p>q){
        int burgerSapi = s;
        if (burgerSapi > (r/2)) burgerSapi = r/2;
        k += burgerSapi * p;
        r -= burgerSapi * 2;

        // Jika mengikuti soal maka burgerAyam = a/2
        int burgerAyam = a;
        if (burgerAyam > (r/2)) burgerAyam = r/2;
        k += burgerAyam * q;
    }else{
        // Jika mengikuti soal maka burgerAyam = a/2
        int burgerAyam = a;
        if (burgerAyam > (r/2)) burgerAyam = r/2;
        k += burgerAyam * q;
        r -= burgerAyam * 2;

        int burgerSapi = s;
        if (burgerSapi > (r/2)) burgerSapi = r/2;
        k += burgerSapi * p;
    }
    cout<<k<<endl;
}