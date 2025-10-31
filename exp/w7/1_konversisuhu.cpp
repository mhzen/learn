#include <iostream>
#include <iomanip>
using namespace std;

struct suhu
{
    float celcius;
    float fahrenheit;
    float kelvin;
};

int input()
{
    int n;
    cout << "Masukkan jumlah data suhu: ";
    cin >> n;
    cin.ignore();
    return n;
}

float toFahrenheit(float celcius)
{
    return (celcius * 9 / 5) + 32;
}

float toKelvin(float celcius)
{
    return celcius + 273.15;
}

void printTable(const suhu* arr, int n)
{
    if (!arr || n <= 0) return;
    cout << left << setw(12) << "Celcius" << setw(12) << "Fahrenheit" << setw(12) << "Kelvin" << endl;
    cout << string(36, '-') << endl;
    cout << fixed << setprecision(2);
    for (int i = 0; i < n; i++)
    {
        cout << right << setw(12) << arr[i].celcius << setw(12) << arr[i].fahrenheit << setw(12) << arr[i].kelvin << endl;
    }
}

int main()
{
    int n = input();
    if (n <= 0) return 0;
    suhu suhuData[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Masukkan data suhu ke-" << i + 1 << " (Celcius): ";
        cin >> suhuData[i].celcius;
        cin.ignore();
        suhuData[i].fahrenheit = toFahrenheit(suhuData[i].celcius);
        suhuData[i].kelvin = toKelvin(suhuData[i].celcius);
    }
    printTable(suhuData, n);
    return 0;
}