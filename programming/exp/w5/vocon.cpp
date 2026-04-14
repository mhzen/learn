#include <iostream>
#include <string>
using namespace std;
int main() {
    string n;
    int v=0, c=0;
    getline(cin, n);
    for (int i=0; i<n.length(); i++){
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