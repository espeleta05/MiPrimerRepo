#include <iostream>
using namespace std;
#include "GraphM.h"

int main() {
    GraphM<char> miGrafo;

    miGrafo.addVertex('a');
    miGrafo.addVertex('b');
    miGrafo.addVertex('c');
    miGrafo.addVertex('d');

    miGrafo.addEdge('a', 'b', 10);
    miGrafo.addEdge('a', 'c', 3);
    miGrafo.addEdge('b', 'd', 7);

    miGrafo.print();

    return 0;
}
 