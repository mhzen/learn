#include<iostream>
using namespace std;

int main(){
    // no case :P
    int bilangan;
    cout<<"Masukkan bilangan = ";
    cin>>bilangan;

    switch(bilangan){
        case 1:
            cout<<"Hari ke 1 adalah hari Senin"<<endl;
            break;
        case 2:
            cout<<"Hari ke 2 adalah hari Selasa"<<endl;
            break;
        case 3:
            cout<<"Hari ke 3 adalah hari Rabu"<<endl;
            break;
        case 4:
            cout<<"Hari ke 4 adalah hari Kamis"<<endl;
            break;
        case 5:
            cout<<"Hari ke 5 adalah hari Jumat"<<endl;
            break;
        case 6:
            cout<<"Hari ke 6 adalah hari Sabtu"<<endl;
            break;
        case 7:
            cout<<"Hari ke 7 adalah hari Minggu"<<endl;
            break;
        default:
            cout<<"Nilai hari tidak valid"<<endl;
    }

    return 0;
}