#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int tukarByValue(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    return a, b;
}

int tukarByReference(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
    return a, b;
}

int main()
{
    int a, b;
    cout << "Masukkan bilangan pertama: ";
    cin >> a;
    cout << "Masukkan bilangan kedua: ";
    cin >> b;
    cout << "Sebelum ditukar: a = " << a << ", b = " << b << endl;
    tukarByValue(a, b);
    cout << "Setelah tukarByValue: a = " << a << ", b = " << b << endl;
    tukarByReference(a, b);
    cout << "Setelah tukarByReference: a = " << a << ", b = " << b << endl;
    return 0;
}