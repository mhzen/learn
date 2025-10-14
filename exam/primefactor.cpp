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