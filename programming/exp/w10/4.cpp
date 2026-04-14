#include <iostream>
using namespace std;

void seqSearch(int arr[], int size, int target)
{
    int muncul = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            muncul++;
        }
    }
    cout << endl;
    cout << "Jumlah kemunculan = " << muncul << endl;
}

int main()
{
    int jumlah;
    cout << "Jumlah data: ";
    cin >> jumlah;
    int data[jumlah] = {0};

    for (int i = 0; i < jumlah; i++)
    {
        cin >> data[i];
    }

    cout << "Target: ";
    int target;
    cin >> target;

    seqSearch(data, jumlah, target);
}