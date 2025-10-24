#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct mahasiswa
{
    string nama;
    string niu;
    float ipk;
};

main()
{
    int n;
    cin >> n;
    cin.ignore();
    int max = n;
    mahasiswa mhs[n];
    for (int i = 0; i < n; i++)
    {
        getline(cin, mhs[i].nama);
        getline(cin, mhs[i].niu);
        cin >> mhs[i].ipk;
        cin.ignore();
    }
    cout << left << setw(20) << "Nama" << setw(10) << "NIU" << setw(5) << "IPK" << endl;
    cout << string(35, '-') << endl;
    cout << fixed << setprecision(2);
    for (int i = 0; i < n; i++)
    {
        cout << left << setw(20) << mhs[i].nama << setw(10) << mhs[i].niu << setw(5) << mhs[i].ipk << endl;
    }
}