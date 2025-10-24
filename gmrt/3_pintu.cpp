#include<bits/stdc++.h>
using namespace std;

int main(){
    int x, a, b, c;
    cin>>x>>a>>b>>c;

    bool k = false;
    if (x == 3){
        if (c == 2){
            if (b==1){
                k=true;
            }
        }else if (c == 1){
            if (a==2){
               k=true;
            }
        }
    } else if (x == 2){
        if (b == 3){
            if (c==1){
                k=true;
            }
        }else if (b == 1){
            if (a==3){
                k=true;
            }
        }
    } else if (x == 1){
        if (a == 3){
            if (c==2){
                k=true;
            }
        }else if (a == 2){
            if (b==3){
                k=true;
            }
        }
    }

    if (k==true){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}