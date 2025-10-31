#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    cout << "Masukkan jumlah nilai: ";
    int n;
    cin >> n;
    int* nilai = new int[n];
    int nilaiTotal = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "Nilai ke-" << i + 1 << ": ";
        cin >> nilai[i];
        nilaiTotal += nilai[i];
    }
    float rataRata = static_cast<float>(nilaiTotal) / n;
    cout << fixed << setprecision(2);
    cout << "Rata-rata: " << rataRata << endl;
    if (rataRata >= 70)
    {
        cout << "Lulus" << endl;
    }
    else
    {
        cout << "Tidak Lulus" << endl;
    }
}
