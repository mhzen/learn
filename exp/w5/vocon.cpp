#include <iostream>
#include <cstring>
using namespace std;
int main() {
    // string n;
    char n[100];
    int v=0, c=0;
    // getline(cin, n);
    cin.getline(n, 100);
    // for (int i=0; i<n.length(); i++){
    for (int i=0; i<strlen(n); i++){
        // if (n[i] == 'a' || n[i] == 'A' || n[i] == 'i' || n[i] == 'I' || n[i] == 'u' || n[i] == 'U' || n[i] == 'e' || n[i] == 'E' || n[i] == 'o' || n[i] == 'O'){
        //     v++;
        // } else if (n[i]>'a' && n[i]<='z' || n[i]>'A' && n[i]<='Z') {
        //     c++;
        // }
        switch (n[i]) {
            case 'a': case 'A':
            case 'e': case 'E':
            case 'i': case 'I':
            case 'o': case 'O':
            case 'u': case 'U':
                v++; break;
            default:
                if ((n[i]>'a' && n[i]<='z')||(n[i]>'A' && n[i]<='Z')) c++; break;
        }
    }
    cout<<"vokal: "<<v<<endl<<"konsonan: "<<c<<endl;
    return 0;
}