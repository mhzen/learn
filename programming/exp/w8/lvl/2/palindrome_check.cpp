#include<iostream>
using namespace std;

bool is_palindrome(string str, int left, int right) {
    if (left >= right) return true;
    if (str[left] != str[right]) return false;
    return is_palindrome(str, left + 1, right - 1);
}

int main(){
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    int n = str.length();
    if (is_palindrome(str, 0, n - 1)) {
        cout << "\"" << str << "\" is a palindrome." << endl;
    } else {
        cout << "\"" << str << "\" is not a palindrome." << endl;
    }

    return 0;
}