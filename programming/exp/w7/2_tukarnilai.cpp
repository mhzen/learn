#include <iostream>
using namespace std;
int x, y;

void tukarByValue(int a, int b)
{
    x = b;
    y = a;
}

void tukarByReference(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    cout << "Masukkan bilangan pertama: ";
    cin >> x;
    cout << "Masukkan bilangan kedua: ";
    cin >> y;

    cout << "Sebelum ditukar: a = " << x << ", b = " << y << endl;

    tukarByValue(x, y);
    cout << "Setelah tukarByValue: a = " << x << ", b = " << y << endl;
    tukarByValue(x, y);

    tukarByReference(x, y);
    cout << "Setelah tukarByReference: a = " << x << ", b = " << y << endl;
}