#include<iostream>
#include<iomanip>
using namespace std;

float hitungRataRata(int arr[], int n){
    int total = 0;
    for (int i=0; i<n; i++){
        total += arr[i];
    }
    // https://www.geeksforgeeks.org/cpp/static_cast-in-cpp/
    return (static_cast<float>(total) / n);
}

void tampilkanKelulusan(float rataRata){
    if (rataRata >= 70){
        cout<<"Status : LULUS"<<endl;
    }else{
        cout<<"Status : TIDAK LULUS"<<endl;
    }
}

main(){
    int n;
    cout<<"Masukkan jumlah nilai: ";
    cin>>n;
    int nilai[n] = {0};
    for (int i=0; i<n; i++){
        cout<<"Nilai ke-"<<i+1<<": ";
        cin >> nilai[i];
    }

    float rataRata = hitungRataRata(nilai, n);
    cout<<fixed<<setprecision(2)<<"Rata-rata: "<<rataRata<<endl;
    tampilkanKelulusan(rataRata);
}