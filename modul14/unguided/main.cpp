#include <iostream>
#include "graph.h"
#include "graph.cpp"

using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');

    ConnectNode(FindNode(G,'A'), FindNode(G,'B'));
    ConnectNode(FindNode(G,'A'), FindNode(G,'C'));
    ConnectNode(FindNode(G,'B'), FindNode(G,'D'));
    ConnectNode(FindNode(G,'C'), FindNode(G,'E'));

    cout << "=== GRAPH ===" << endl;
    PrintInfoGraph(G);

    cout << "\nDFS mulai dari A: ";
    PrintDFS(G, FindNode(G,'A'));

    adrNode P = G.First;
    while (P != NULL) {
        P->visited = 0;
        P = P->Next;
    }

    cout << "\nBFS mulai dari A: ";
    PrintBFS(G, FindNode(G,'A'));

    return 0;
}