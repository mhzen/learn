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
    cout<<"Cumlaude (IPK >= 3.50):"<<endl;
    cout<<fixed<<setprecision(2);
    for (int i=0; i<n; i++){
        if (mhs[i].ipk >= 3.50){
            cout<<mhs[i].nama<<" - "<<mhs[i].niu<<" - "<<mhs[i].ipk<<endl;
        }
    }
}