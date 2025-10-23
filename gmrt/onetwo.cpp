#include<bits/stdc++.h>
using namespace std;

int check(int a, int b){
    bool k=0;
    if (a%2==0 && b%2==0){
        k=1;
    }else if (a%2==0 && b==0){
        k=1;
    }else if (b%2==0 && a==0){
        k=1;
    }else if (a == (2*b)){
        k=1;
    }
    return k;
}

int main(){
    int a, b, k;
    cin>>a>>b;
    k = check(a, b);
    if (k==true){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}