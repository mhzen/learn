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
    for (int i = 0; i < n; i++){
        getline(cin, mhs[i].nama);
        getline(cin, mhs[i].niu);
        cin >> mhs[i].ipk;
        cin.ignore();
    }
    cout << "Cumlaude (IPK >= 3.50):" << endl;
    cout << fixed << setprecision(2);
    bool adaCumlaude = 0;
    for (int i = 0; i < n; i++){
        if (mhs[i].ipk >= 3.50)
        {
            cout << mhs[i].nama << " - NIU " << mhs[i].niu << " - IPK " << mhs[i].ipk << endl;
            adaCumlaude = 1;
        }
    }
    if (adaCumlaude != 1)
        cout << "Tidak ada mahasiswa cumlaude.";
}