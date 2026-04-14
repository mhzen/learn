#include<iostream>
using namespace std;

int main(){
    int n = 3;
    int arr[n][n] = {0};
    int sum[n] = {0};
    for (int i = 0; i<n; i++){
        cout << "Nilai Mahasiswa " << i + 1 << " (MK1 MK2 MK3): ";
        for (int j = 0; j < n; j++){
            cin>>arr[i][j];
            sum[i] += arr[i][j];
        }
    }
    for (int i = 0; i<n; i++){
        cout << "Rata-rata Mahasiswa "<< i+1 <<": " << (float)(sum[i] / n) << endl;
    }
}