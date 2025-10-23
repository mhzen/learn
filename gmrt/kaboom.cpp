#include<bits/stdc++.h>
using namespace std;

// 1-60, skip jika kelipatan 3 & 5, output KABOOM jika kelipatan 15 (skip juga karena KPK 3 & 5)

int main(){
    for (int i=1; i<=60; i++){
        if (i%15==0){
            cout<<"KABOOM"<<endl;
            continue;
        } else if (i%3==0 || i%5==0){
            continue;
        }
        cout<<i<<endl;
    }

    // int k=1;
    // while (k<=60){
    //     if (k%15==0){
    //         cout<<"KABOOM"<<endl;
    //         continue;
    //     } else if (k%3==0 || k%5==0){
    //         continue;
    //     }
    //     cout<<k<<endl;
    //     kk++;
    // }
}