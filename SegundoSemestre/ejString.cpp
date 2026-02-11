#include <iostream>
using namespace std;
#include <string>

int main()
{
    /*string s1, s2, s3;
    cout<<"Dame el s1 ";
    getline(cin, s1);
    cout<<"Dame el s2 ";
    getline(cin, s2);
    s3=s1+s2;
    cout<<s3;
    */
    string s1 = "hyper Text Markup Language", s2;
    s2 = s1[0];
    int pos = s1.find(" ");
    while (pos !=-1)
    {
        s2= s2+s1[pos + 1];
        s1.erase(0, pos+1);
        pos = s1.find(" ");
    }
    cout << s2;
    return 0;
}