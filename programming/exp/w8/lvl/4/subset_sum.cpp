#include<iostream>
using namespace std;

// example io
// arr = [2, 3, 5, 6, 8, 10]
// sum = 10
// Possible subsets of arr that sum to 10 are:
// [2, 8]
// [10]
// [5, 3, 2]
// ✅ Total = 3 subsets

void subset_sum(int arr[], int n, int index, int current_sum, int target_sum, string current_subset = "") {
    if (index == n) {
        if (current_sum == target_sum) {
            cout << "[" << current_subset.substr(0, current_subset.length() - 2) << "]" << endl;
        }
        return;
    }

    // Include the current element
    subset_sum(arr, n, index + 1, current_sum + arr[index], target_sum, current_subset + to_string(arr[index]) + ", ");

    // Exclude the current element
    subset_sum(arr, n, index + 1, current_sum, target_sum, current_subset);
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

    int target_sum;
    cout << "Enter the target sum: ";
    cin >> target_sum;

    cout << "Possible subsets of arr that sum to " << target_sum << " are:" << endl;
    subset_sum(arr, n, 0, 0, target_sum);

    return 0;
}