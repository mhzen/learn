#include <iostream>
using namespace std;

void swap(int &kiri, int &kanan){
    int temp = kiri;
    kiri = kanan;
    kanan = temp;
}

void bubblesort(int arr[], int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size - 1 - i; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
    for (int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int size = 8;
    int arr[size] = {8, 7, 5, 4, 3, 2, 9, 98};
    bubblesort(arr, size);
}