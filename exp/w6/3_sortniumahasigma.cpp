#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
struct mahasiswa
{
    string nama;
    string niu;
    float ipk;
};

int main()
{
    int n;
    cin>>n;
    string dummy;
    cin.ignore();
    mahasiswa mhs[1000];
    for (int i=0; i<n; i++){
        getline(cin, mhs[i].nama);
        getline(cin, mhs[i].niu);
        cin>>mhs[i].ipk;
        cin.ignore();
    }

    // bubble sort https://www.geeksforgeeks.org/cpp/bubble-sort-in-cpp/
    for (int i=0; i<(n-1); i++){
        for (int j=0; j<(n-i-1); j++){
            if (mhs[j].niu > mhs[j+1].niu){
                mahasiswa temp = mhs[j];
                mhs[j] = mhs[j+1];
                mhs[j+1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++){
        cout << mhs[i].niu << " | "
             << mhs[i].nama << " | "
             << fixed << setprecision(2) << mhs[i].ipk << endl;
    }
}