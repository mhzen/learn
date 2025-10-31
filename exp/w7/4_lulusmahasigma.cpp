#include <iostream>
#include <iomanip>
using namespace std;

float hitungRata(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; ++i) total += arr[i];
    return static_cast<float>(total) / n;
}

void tampilStatus(float rata) {
    if (rata >= 70.0)
        cout << "Status : LULUS" << endl;
    else
        cout << "Status : TIDAK LULUS" << endl;
}

int main() {
    cout << "Masukkan jumlah nilai: ";
    int n;
    if (!(cin >> n) || n <= 0) return 0;

    int nilai[n];
    for (int i = 0; i < n; ++i) {
        cout << "Nilai ke-" << i + 1 << ": ";
        cin >> nilai[i];
    }

    float rataRata = hitungRata(nilai, n);
    cout << fixed << setprecision(2);
    cout << "Rata-rata: " << rataRata << endl;
    tampilStatus(rataRata);

    return 0;
}