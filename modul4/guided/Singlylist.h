#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>

#define Nil NULL

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List
{
    address First;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &p);
void insertFirst(List &L , address P);
void insertlast(List &L , address P);
void PrintInfo(List L);

#endif