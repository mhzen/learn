#include<iostream>
using namespace std;

void linear_search(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            cout << "Element found at index: " << i << endl;
            return;
        }
    }
    cout << "Element not found in the array." << endl;
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

    int target;
    cout << "Enter the target value to search for: ";
    cin >> target;
    linear_search(arr, n, target);
}