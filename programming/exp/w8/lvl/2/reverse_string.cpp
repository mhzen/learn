#include<iostream>
using namespace std;

string reverse_string(string str, int n) {
    if (n == 0) return "";
    return str[n - 1] + reverse_string(str, n - 1);
}

int main(){
    string str;
    getline(cin, str);

    int n = str.length();

    string reversed = reverse_string(str, n);
    cout << reversed << endl;

    return 0;
}