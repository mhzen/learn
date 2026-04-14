#include <iostream>
using namespace std;

void seqSearch(int arr[], int size)
{
    int maks = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > maks)
        {
            maks = arr[i];
        }
    }
    cout << endl;
    cout << "Nilai maksimum: " << maks << endl;
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

    seqSearch(data, jumlah);
}