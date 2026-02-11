#include <iostream>
using namespace std;
int testing(int a, int b){
    int c;    
    if(a<b){
        c=a+b;        
    }else{
        c=a-b;
    }
    return c;
}

int main(){
    int a, b;
    cout<<"Dame un numero: "<<endl;
    cin>>a;
    cout<<"Dame otro numero: "<<endl;
    cin>>b;

    cout<<"La operacion es: "<<testing(a,b)<<endl;

    return 0;
}