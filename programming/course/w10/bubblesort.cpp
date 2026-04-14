#include <iostream>
using namespace std;

int main()
{
    int n = 5;
    int k[n] = {5, 3, 8, 4, 2};

    // Selection Sort
    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-i-1; j++){
            if (k[j] > k[j+1]){
                // Tukar
                int temp = k[j];
                k[j] = k[j+1];
                k[j+1] = temp;
            }
        }
    }

    for (int i=0; i<n; i++){
        cout << k[i] << " ";
    }

    return 0;
}

