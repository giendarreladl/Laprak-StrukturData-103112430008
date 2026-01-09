#ifndef GRAF_H_INCLUDED
#define GRAF_H_INCLUDED

#include <iostream>
using namespace std;

typedef char InfoGraph;

struct ElmNode;
struct ElmEdge;

typedef ElmNode* adrNode;
typedef ElmEdge* adrEdge;

struct ElmNode
{
    InfoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge
{
    adrNode Node;     // <<< sesuaikan dengan graf.cpp (Node)
    adrEdge next;
};

struct Graph
{
    adrNode first;
};

void createGraph(Graph &G);

adrNode AllocateNode(InfoGraph X);
adrEdge AllocateEdge(adrNode N);

void insertNode(Graph &G, InfoGraph X);

adrNode FindNode(Graph G, InfoGraph X);   // <<< diperbaiki (bukan void)

void ConnectNode(Graph &G, InfoGraph A, InfoGraph B);

void PrintInfoGraph(Graph G);

void ResetVisited(Graph &G);
void PrintDFS(Graph &G, adrNode N);
void PrintBFS(Graph &G, adrNode N);

#endif
