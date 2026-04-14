#include<iostream>
using namespace std;

void print_numbers_to_n(int n) {
    if (n == 0) {
        cout << "0 ";
        return;
    }
    if (n > 0) {
        print_numbers_to_n(n - 1);
        cout << n << " ";
    } else {
        print_numbers_to_n(n + 1);
        cout << n << " ";
    }
}

void print_numbers_from_n(int n) {
    if (n == 0) {
        cout << "0 ";
        return;
    }
    cout << n << " ";
    if (n > 0) {
        print_numbers_from_n(n - 1);
    } else {
        print_numbers_from_n(n + 1);
    }
}

int main() {
    int number;
    cout << "Enter an integer: ";
    cin >> number;

    cout << "Numbers from 0 to " << number << " are: ";
    print_numbers_to_n(number);
    cout << endl;
    cout << "Numbers from " << number << " to 0 are: ";
    print_numbers_from_n(number);
    cout << endl;

    return 0;
}