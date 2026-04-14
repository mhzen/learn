#include<iostream>

using namespace std;

int main() {
    // ni1 = nilai 1, ni2 = nilai 2, dst
    int ni1, ni2, ni3, ni4, ni5;

    cin>>ni1>>ni2>>ni3>>ni4>>ni5;

    if (ni1>=80){
        ni1=4;
    }else if(ni1>=70){
        ni1=3;
    }else if(ni1>=60){
        ni1=2;
    }else if(ni1>=50){
        ni1=1;
    }else{
        ni1=0;
    }

    if (ni2>=80){
        ni2=4;
    }else if(ni2>=70){
        ni2=3;
    }else if(ni2>=60){
        ni2=2;
    }else if(ni2>=50){
        ni2=1;
    }else{
        ni2=0;
    }

    if (ni3>=80){
        ni3=4;
    }else if(ni3>=70){
        ni3=3;
    }else if(ni3>=60){
        ni3=2;
    }else if(ni3>=50){
        ni3=1;
    }else{
        ni3=0;
    }

    if (ni4>=80){
        ni4=4;
    }else if(ni4>=70){
        ni4=3;
    }else if(ni4>=60){
        ni4=2;
    }else if(ni4>=50){
        ni4=1;
    }else{
        ni4=0;
    }

    if (ni5>=80){
        ni5=4;
    }else if(ni5>=70){
        ni5=3;
    }else if(ni5>=60){
        ni5=2;
    }else if(ni5>=50){
        ni5=1;
    }else{
        ni5=0;
    }

    float gpa = (ni1 + ni2 + ni3 + ni4 + ni5) / 5.00;

    // Agar dua angka dibelakang koma
    int gpaKali100 = gpa * 100;
    int gpaBulat = gpaKali100 / 100;
    int gpaDesimal = gpaKali100 % 100;

    cout<<gpaBulat<<"."<<(gpaDesimal < 10 ? "0" : "")<< gpaDesimal << endl;
    
    cout<<(gpa >= 2.75 ? "PASSED" : "FAILED");

    return 0;
}