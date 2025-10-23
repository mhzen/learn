#include<bits/stdc++.h>
using namespace std;

// a^n

int squared(int a, int n){
    int k=1;
    for (int i=1; i<=n; i++){
        k *= a;
    }
    return k;
}

int main(){
    int a, n;
    cin>>a>>n;
    cout<<squared(a, n)<<endl;
    return 0;
}