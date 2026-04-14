#include <iostream>
#include <string>
using namespace std;
int main() {
    string n;
    int v=0;
    getline (cin, n);
    for (int i=0; i<n.length(); i++){
        switch (n[i]) {
            case 'a': case 'A': v++; break;
            case 'e': case 'E': v++; break;
            case 'i': case 'I': v++; break;
            case 'o': case 'O': v++; break;
            case 'u': case 'U': v++; break;
        }
    }
    cout<<v<<endl;
    return 0;
}