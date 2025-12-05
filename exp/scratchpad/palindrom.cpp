#include<iostream>
#include<string>
#include<cctype>
using namespace std;

bool check(string str){
    string temp;
    int panjang = str.length();
    for (int i = 0; i<panjang; i++){
        str[i] = tolower(str[i]);
    }
    for (int i = panjang-1; i>=0; i--){
        temp += str[i];
    }
    return str == temp;
}

int main(){
    string str;
    cin>>str;
    bool checking = check(str);
    if (checking){
        cout<<"Palindrom";
    }else{
        cout<<"Bukan Palindrom";
    }
}