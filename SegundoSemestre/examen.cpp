#include <iostream>
using namespace std;

int main(){
    int x=2, *p, *t;
    p = new int (6);
    t = &x;
    cout<<*p<<" "<<*t<<endl;
    *t=4;
    t=p;
    *p=1;
    cout<<*p<<" "<<*t<<endl;
    cout<<x<<endl;
    t= new int(8);
    x++;
    *p=*p-1;
    cout<<*p<<" "<<*t<<endl;
    cout<<x<<endl;
    
    return 0;
}