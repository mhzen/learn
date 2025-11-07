/*
Program ini menghitung f(n) menggunakan sebuah fungsi rekursi.

Aturannya sebagai berikut:
- Jika n adalah bilangan ganjil, maka f(n) = n * f(n-1)
- Jika n adalah bilangan genap, maka f(n) = (n/2) * f(n-1)
= Jika n <= 1, maka f(n) = 1 dan rekursi berhenti.

Contoh:
- f(5) = 5 * f(4) = 5 * ((4/2) * f(3)) = 5 * 2 * (3 * f(2)) = 5 * 2 * 3 * ((2/2) * f(1)) = 5 * 2 * 3 * 1 * 1 = 30
*/

#include <iostream>
using namespace std;

// Variabel long untuk menangani nilai besar
long hitungF(int n)
{
    // Basis
    if (n <= 1)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        return (n / 2) * hitungF(n - 1);
    }
    else
    {
        return n * hitungF(n - 1);
    }
}

int main()
{
    int n;

    cout << "Masukkan nilai n: ";
    cin >> n;

    cout << "f(" << n << ") = " << hitungF(n) << endl;

    return 0;
}