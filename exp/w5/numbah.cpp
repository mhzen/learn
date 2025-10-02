#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int m[n];
    int k[10] = {0};
    for (int i=0; i<n; i++) {
        cin>>m[i];
        for (int j=1; j<=10; j++) {
            if (m[i]==j) {
                k[j-1] += 1;
            }
        }
    }
    for (int i=0; i<10; i++) {
        cout<<(i+1)<<" : "<<k[i]<<endl;
    }
}