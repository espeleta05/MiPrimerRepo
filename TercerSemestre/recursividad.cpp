#include <iostream>
#include <chrono>
using namespace std;

int fib(int n){
    if (n<2){
        return 1;
    }else{
        return fib(n-2)+fib(n-1);
    }
}

int main(){
    int n;
    cout<< "Dame el valor de n ";
    cin>>n;
    cout<<fib(n)<<endl;
    return 0;
}