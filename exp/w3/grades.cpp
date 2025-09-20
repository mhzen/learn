#include<iostream>
using namespace std;

int main() {
    int input;

    cin>>input;

    if (input>=80){
        cout<<"A";
    }else if (input>=60){
        cout<<"B";
    }else if (input>=40){
        cout<<"C";
    }else if (input>=20){
        cout<<"D";
    }else{
        cout<<"E";
    }
}