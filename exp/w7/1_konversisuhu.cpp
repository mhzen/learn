#include<iostream>
#include<iomanip>
using namespace std;

struct suhu{
    float celcius;
    float fahrenheit;
    float kelvin;
};

float toFahrenheit(float celcius){
    return (celcius * 9 / 5) + 32;
}

float toKelvin(float celcius){
    return celcius + 273.15;
}

main(){
    cout<<"Masukkan jumlah data suhu: ";
    int n;
    cin>>n;
    suhu suhuData[n];
    for (int i=0; i<n; i++){
        cout<<"Masukkan suhu ke-"<<i+1 <<" (Celcius): ";
        cin>>suhuData[i].celcius;
        suhuData[i].fahrenheit = toFahrenheit(suhuData[i].celcius);
        suhuData[i].kelvin = toKelvin(suhuData[i].celcius);
    }
    cout<<left<<setw(15)<<"Celcius"<<setw(15)<<"Fahrenheit"<<setw(15)<<"Kelvin"<<endl;
    cout<<string(45, '-')<<endl;
    cout<<fixed<<setprecision(2);
    for (int i=0; i<n; i++){
        cout<<right<<setw(15)<<suhuData[i].celcius<<setw(15)<<suhuData[i].fahrenheit<<setw(15)<<suhuData[i].kelvin<<endl;
    }
}