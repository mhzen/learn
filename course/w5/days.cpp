#include<iostream>
using namespace std;

int main(){
    // given a number
    // output the corresponding day in the week
    int nomor;
    char hari;
    cin>>nomor;
    switch (nomor)
    {
        case 1 : cout<<"Senin"<<endl; break; 
        case 2 : cout<<"Selasa"<<endl; break; 
        case 3 : cout<<"Rabu"<<endl; break; 
        case 4 : cout<<"Kamis"<<endl; break; 
        case 5 : cout<<"Jumat"<<endl; break; 
        case 6 : cout<<"Sabtu"<<endl; break; 
        case 7 : cout<<"Minggu"<<endl; break; 
        default : cout<<"Invalid"<<endl;
    }

    return 0;
}