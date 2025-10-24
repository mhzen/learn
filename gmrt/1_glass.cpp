#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    cin>>a>>b>>c;
    int k=0, target=abs(a+b)/2, big=a;
    if (b>a) big=b;
    while (big>target){
        k++;
        big-=c;
    }
    cout<<k<<endl;
}