#include<iostream>
using namespace std;

unsigned long long nth_fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return nth_fibonacci(n - 1) + nth_fibonacci(n - 2);
}

int main() {
    int number;
    cout << "Enter a positive integer: ";
    cin >> number;

    if (number < 0) {
        cout << "Please enter a non-negative integer." << endl;
    } else {
        int result = nth_fibonacci(number);
        cout << "The " << number << "th Fibonacci number is " << result << endl;
    }

    return 0;
}