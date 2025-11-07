#include<iostream>
using namespace std;

// Example: Input "abc" → Output: ["", "a", "b", "c", "ab", "ac", "bc", "abc"]

void generate_subsets(string str, int index, string current, int n) {
    if (index == n) {
        cout << "\"" << current << "\"" << endl;
        return;
    }
    // Exclude the current character
    generate_subsets(str, index + 1, current, n);
    // Include the current character
    generate_subsets(str, index + 1, current + str[index], n);
}

int main(){
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    int n = str.length();

    cout << "All subsets of the string are:" << endl;
    generate_subsets(str, 0, "", n);
}