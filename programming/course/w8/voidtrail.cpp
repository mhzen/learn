#include<iostream>
using namespace std;
void luas (int &ls, int p, int l){
    ls = p*l;
}

int lwas(int p, int l){
    return (p*l);
}

int main(){
    int pj,lb,hsl;
    cin>>pj>>lb;
    // luas(hsl,pj,lb);
    // cout<<hsl;
    cout<<lwas(pj,lb);
    return 0;
}