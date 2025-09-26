#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    int ulang;
    string data1, data2, data3;
    ifstream file("Praktikum.txt");
    if(file){
        file>>data1>>data2>>data3;
        file.close();
    }

    cout<<"Masukkan jumlah pengulangan: ";
    cin>>ulang;

    for(int i=0; i<ulang; i++){
        cout<<data1<<" "<<data2<<" "<<data3<<endl;
    }
    return 0;
}