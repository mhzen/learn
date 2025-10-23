#include<bits/stdc++.h>
using namespace std;

int main(){
    double a, b, c;
    // bool zero=false;
    cout<<"ax^2+bx+c"<<endl;
    cin>>a>>b>>c;
    double x1 = (-b + sqrt((b*b)-(4*a*c)))/(2*a);
    double x2 = (-b - sqrt((b*b)-(4*a*c)))/(2*a);
    // if ( x1 == 0 || x2 == 0){
    //     zero=true;
    // }
    cout<<x1<<" "<<endl<<x2<<endl;
    bool p = ((a*x1*x1) + (b*x1) + c);
    bool q = ((a*x2*x2) + (b*x2) + c);
    cout<<p<<endl<<q;
}