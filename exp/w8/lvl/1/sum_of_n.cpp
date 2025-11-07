#include<iostream>
using namespace std;

int sum_of_n(int n) {
    if (n == 0) return 0;
    if (n>0){
        return n + sum_of_n(n - 1);
    }else if (n<0){
        return n + sum_of_n(n + 1);
    }
}

int main() {
    int number;
    cout << "Enter an integer: ";
    cin >> number;

    int result = sum_of_n(number);
    cout << "Sum of first " << number << " integer is " << result << endl;

    return 0;
}