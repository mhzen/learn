#include<iostream>

using namespace std;

int main() {
    // Given three input: x, y, and z
    // Output the highest number 
    int x, y, z;
    cin>>x>>y>>z;
    
    // Non nested
    if ((x>y)&&(x>z)) {
       cout<<x<<endl;
    } else if (y>=z) {
        cout<<y<<endl;
    } else {
        cout<<z<<endl;
    }

    // Nested
    if (x>y){
        if (x>z){
            cout<<x<<endl;
        } else {
            cout<<z<<endl;
        }
    }else{
        if (y>z){
            cout<<y<<endl;
        } else {
            cout<<z<<endl;
        }
    }

    return 0;
}