#include<iostream>
using namespace std;

int power(int base, int exp) {
    if (exp == 0) return 1;
    if (exp > 0){
        return base * power(base, exp - 1);
    }else{
        return 1 / power(base, -exp);
    }
}

int main() {
    int base, exp;
    cout << "Enter base and exponent: ";
    cin >> base >> exp;

    double result = power(base, exp);
    cout << base << " raised to the power of " << exp << " is " << result << endl;

    return 0;
}