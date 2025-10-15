// Buatlah program dalam bahasa C++ yang mengambil input sebuah bilangan bulat n dan mengeluarkan output m yaitu banyaknya faktor prima dari n. Sebagai contoh:
// Input n=30, faktor prima dari 30 adalah 2*3*5, maka m=3
// Input n=3300, faktor prima dari 3300 adalah 2*2*3*5*11 maka outputnya: m=4.
#include<iostream>
#include<cmath>
using namespace std;
main(){
    int n;
    int factor = 0;

    cin>>n;

    if (n % 2 == 0){
        factor++;
        while (n % 2 == 0){
            n = n / 2;
        }
    }

    for (int i=3; i<sqrt(n); i=i+2){
        if (n % i == 0){
            factor++;
            while (n % i == 0){
                n = n / i;
            }
        }
    }

    if (n>2){
        factor++;
    }

    cout<<factor<<endl;
}