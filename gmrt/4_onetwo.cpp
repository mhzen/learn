#include<bits/stdc++.h>
using namespace std;

string check(int a, int b){
    string k;
    if (
        a%2==0 && b%2==0 ||
        a%2==0 && b==0 ||
        b%2==0 && a==0 ||
        a == (2*b)
    ){
        k="YES";
    }else{
        k="NO";
    }
    return k;
}

int main(){
    int a, b;
    cin>>a>>b;
    cout<<check(a, b)<<endl;
    return 0;
}