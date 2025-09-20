#include<iostream>

using namespace std;

// int main (){
//     int x;
//     cin>>x;
// 
//     if (x>=1){
//         if (x==2){
//             cout<<"Not Prime";
//         } else if (x%2!=0){
//             cout<<"Could be Prime";
//         } else {
//             cout<<"Even, Not Prime";
//         }
//     } else {
//         cout<<"Not Positive Integer";
//     }
// }

int main() {
    int x;
    cin >> x;

    if (x>=1){
        if (x%2!=0){
            if (x%x==0){
                cout<<"Prime";
            }else{
                cout<<"Not Prime";
            }
        }else{
            cout<<"Not Prime";
        }
    }else{
        cout<<"Not Prime";
    }
}