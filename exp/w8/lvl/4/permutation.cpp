#include<iostream>
using namespace std;

void permutations(string str, int left, int right) {
    if (left == right) {
        cout << str << endl;
    } else {
        for (int i = left; i <= right; i++) {
            swap(str[left], str[i]);
            permutations(str, left + 1, right);
            swap(str[left], str[i]); // backtrack
        }
    }
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    permutations(str, 0, str.length() - 1);
    return 0;
}