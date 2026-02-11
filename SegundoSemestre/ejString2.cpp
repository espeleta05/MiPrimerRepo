#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1;
    int len, pos;
    bool pal = true;

    cout << "Dame la frase: ";
    getline(cin, s1);

   
    pos = s1.find(" ");
    while (pos != -1) {
        s1.erase(pos, 1);
        pos = s1.find(" ");
    }

    
    len = s1.length();
    for (int i = 0; i < len; i++) {
        s1[i] = tolower(s1[i]);
    }

    
    int i = 0, j = len - 1;
    while (i < j) {
        if (s1[i] != s1[j]) {
            pal = false;
            break;
        }
        i++;
        j--;
    }

    
    if (pal) {
        cout << "La frase es un palindromo" << endl;
    } else {
        cout << "La frase no es un palindromo" << endl;
    }

    return 0;
}
