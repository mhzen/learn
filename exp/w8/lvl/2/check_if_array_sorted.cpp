#include<iostream>
using namespace std;
// Check if an array is sorted in either ascending or descending order using recursion

bool is_sorted(int arr[], int n) {
    // Base case: An array of size 0 or 1 is sorted
    if (n == 0 || n == 1) return true;

    // Check if the array is sorted in ascending order
    bool ascending = true;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            ascending = false;
            break;
        }
    }

    // Check if the array is sorted in descending order
    bool descending = true;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            descending = false;
            break;
        }
    }

    return ascending || descending;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n] = {0};
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (is_sorted(arr, n)) {
        cout << "The array is sorted." << endl;
    } else {
        cout << "The array is not sorted." << endl;
    }

    return 0;
}