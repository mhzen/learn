#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void binSearch(int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;
    bool ada = 0;
    bubbleSort(arr, size);
    cout << "Data Terurut: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == target)
        {
            cout << endl;
            cout << "Ditemukan di indeks " << mid << endl;
            ada = 1;
            break;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        { // arr[mid] > target
            right = mid - 1;
        }
    }
    if (!ada)
    {
        cout << endl;
        cout << "Tidak ditemukan";
    }
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

    binSearch(data, jumlah, target);
}