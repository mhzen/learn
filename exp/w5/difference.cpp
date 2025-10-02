#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int m[n];
    for (int i=0; i<n; i++) {
        cin>>m[i];
    }
    int max = m[0], min = m[0];
    for (int i=0; i<n; i++) {
        if (m[i]<min){
            min = m[i];
        }else if (m[i]>max){
            max = m[i];
        }else {
            continue;
        }
    }
    cout<<abs(max-min);
}