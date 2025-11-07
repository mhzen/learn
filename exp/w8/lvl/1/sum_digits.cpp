#include<iostream>
#include<string>
using namespace std;

int sum_digits(const string &number, int n) {
    if (n == 0) return 0;
    int last_digit = number[n - 1] - '0';
    return last_digit + sum_digits(number, n - 1);
}

int main() {
    string number;
    cout << "Enter an integer: ";
    cin >> number;
    int n = number.length();

    int result = sum_digits(number, n);
    cout << "Sum of digits of " << number << " is " << result << endl;
    return 0;
}