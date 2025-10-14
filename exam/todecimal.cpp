#include<iostream>
#include<string>
#include<cmath>
using namespace std;
main(){
    string n;
    cin>>n;
    int l = n.length();
    int m = 0;
    for (int i=0; i<l; i++){
        if (n[i] == '1'){
            m = m + pow(2, (l-i-1));
        }
    }
    cout<<m<<endl;
}