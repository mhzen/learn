#include<iostream>
using namespace std;

int find_max(int arr[], int n) {
    if (n == 1) return arr[0];
    int max_of_rest = find_max(arr, n - 1);
    return (arr[n - 1] > max_of_rest) ? arr[n - 1] : max_of_rest;
}

int main(){
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n] = {0};
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int max_value = find_max(arr, n);
    cout << "The maximum value in the array is: " << max_value << endl;
}