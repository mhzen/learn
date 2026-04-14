#include<iostream>
using namespace std;

void tower_of_hanoi(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        cout << "Move disk 1 from rod " << source << " to rod " << target << endl;
        return;
    }
    tower_of_hanoi(n - 1, source, auxiliary, target);
    cout << "Move disk " << n << " from rod " << source << " to rod " << target << endl;
    tower_of_hanoi(n - 1, auxiliary, target, source);
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    tower_of_hanoi(n, 'A', 'C', 'B');

    return 0;
}