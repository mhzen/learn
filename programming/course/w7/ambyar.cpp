#include <iostream>
using namespace std;
int main() {
    int n, a, b, ambyar, f, m;
    int data[15] = {13, 17, 25, 28, 30, 41, 45, 56, 58, 64, 73, 76, 87, 91, 98};
    n=14; a=0; b=n; ambyar=0;
    while (a<=b) {
        m=(a+b)/2;
        ambyar+=data[m];
        if (data[m]==f) {
            break;
        } else if (data[m]<f) {
            a=m+1;
        } else {
            b=m-1;
        }
    }
    cout<<ambyar<<endl;
}