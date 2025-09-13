#include<iostream>

using namespace std;

main(){
    int speed;
    int distance;
    int time;

    cout << "Masukkan kecepatan (dalam km/jam): ";
    cin >> speed;
    cout << "Masukkan jarak (dalam km): ";
    cin >> distance;

    time = distance / speed;
    cout << "Kecepatan Akhir: ";
    cout << time << " jam" << endl;
}