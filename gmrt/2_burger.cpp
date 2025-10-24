#include<bits/stdc++.h>
using namespace std;

int main(){
    int r, s, a, p, q;
    cin>>r>>s>>a>>p>>q;
    int k=0;
    if (p>q){
        int burgerSapi = s;
        if (burgerSapi > (r/2)) burgerSapi = r/2;
        k += burgerSapi * p;
        r -= burgerSapi * 2;

        int burgerAyam = a/2;
        if (burgerAyam > (r/2)) burgerAyam = r/2;
        k += burgerAyam * q;
    }else{
        int burgerAyam = a/2;
        if (burgerAyam > (r/2)) burgerAyam = r/2;
        k += burgerAyam * q;
        r -= burgerAyam * 2;

        int burgerSapi = s;
        if (burgerSapi > (r/2)) burgerSapi = r/2;
        k += burgerSapi * p;
    }
    cout<<k<<endl;
}