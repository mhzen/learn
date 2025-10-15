// Dipunyai sebuah larikan(Array 1 dimensi) yang berisi N buah data bilangan bulat,
// data tersebut merupakan data curah hujan di suatu tempat yang diukur setiap harinya(N hari).
// Buatlah program komputer untuk menentukan maksimum kenaikan curah hujan dalam N data tersebut.
// Contoh input dan outputnya Input : N = 10 dan Larikan berisi data : 99, 101, 96, 105, 107, 106, 104, 109, 108, 92
// outputnya : maximum kenaikan curah hujan = 9.(105 - 96)
// Input : N = 5 dan Larikan berisi data : 93, 96, 105, 97, 107
// outputnya : maximum kenaikan curah hujan = 10(107 - 97)

#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n;
    cin>>n;
    int m[n] = {0};

    for (int i = 0; i<n; i++){
        cin>>m[i];
    }

    int o = m[1] - m[0];

    for (int i = 2; i<n; i++){
        int k = m[i] - m[i-1];
        if (k > o){
            o = k;
        }
    }

    cout<<o<<endl;

    return 0;
}