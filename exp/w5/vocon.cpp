#include <iostream>
#include <string>
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
        switch (n[i]) {
            case 'a': case 'A': v++; break;
            case 'e': case 'E': v++; break;
            case 'i': case 'I': v++; break;
            case 'o': case 'O': v++; break;     
            case 'u': case 'U': v++; break;
            case ' ': continue; break;
            default: c++; break;
        }
    }
    cout<<"vokal: "<<v<<endl<<"konsonan: "<<c<<endl;
    return 0;
}