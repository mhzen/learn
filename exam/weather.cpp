#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n;
    cin>>n;
    int m[n] = {0};

    for (int i = 0; i<n; i++){
        cin>>m[i];
    }

    int o = m[1] - m[0];

    for (int i = 2; i<n; i++){
        int k = m[i] - m[i-1];
        if (k > o){
            o = k;
        }
    }

    cout<<o<<endl;

    return 0;
}