#include <iostream>
using namespace std;

int main() {
    int i=20;
    do
    {
        cout << i << " ";
        i--;
    } while (i > 7);
    cout<<"countdown aborted!"<<endl;

    return 0;
}