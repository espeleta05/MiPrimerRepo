#include <iostream>
using namespace std;

#include "GrafoL.h"


int main() {
    GrafoL<char> g;
    g.addVertex('A');
    g.addVertex('B');
    g.addVertex('C');
    g.addVertex('D');
    g.addVertex('E');
    g.addEdge('A','B');
    g.addEdge('A','C');
    g.addEdge('A','E');
    g.addEdge('B','D');
    g.addEdge('C','D');
    g.addEdge('D','E');

    g.print();
    return 0;
}
