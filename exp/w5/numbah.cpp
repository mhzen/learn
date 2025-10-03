#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int k[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i=0; i<n; i++) {
        int m;
        cin>>m;
        if (m>=1 && m<=10){
            k[m-1]++;
        }
    }
    for (int i=0; i<10; i++) {
        cout<<(i+1)<<" : "<<k[i]<<endl;
    }
    return 0;
}