#include "circularlist.h"
#include <iostream>
using namespace std;

void createList(List &L)
{
  L.first = Nil;
}

address alokasi(infotype x)
{
  address P = new elmList;
  P->info = x;
  P->next = Nil;
  return P;
}

void dealokasi(address &P)
{
  delete P;
  P = Nil;
}

void insertFirst(List &L, address P)
{
  if (L.first == Nil)
  {
    L.first = P;
    P->next = L.first;
  }
  else
  {
    address last = L.first;
    while (last->next != L.first)
    {
      last = last->next;
    }
    P->next = L.first;
    L.first = P;
    last->next = L.first;
  }
}

void insertLast(List &L, address P)
{
  if (L.first == Nil)
  {
    L.first = P;
    P->next = L.first;
  }
  else
  {
    address last = L.first;
    while (last->next != L.first)
    {
      last = last->next;
    }
    last->next = P;
    P->next = L.first;
  }
}

void insertAfter(List &L, address Prec, address P)
{
  if (Prec != Nil)
  {
    P->next = Prec->next;
    Prec->next = P;
  }
}

address findElm(List L, infotype x)
{
  if (L.first == Nil)
    return Nil;
  address P = L.first;
  do
  {
    if (P->info.nim == x.nim)
      return P;
    P = P->next;
  } while (P != L.first);
  return Nil;
}

void printInfo(List L)
{
  if (L.first == Nil)
  {
    cout << "List kosong" << endl;
    return;
  }
  address P = L.first;
  do
  {
    cout << "Nama: " << P->info.nama
         << ", NIM: " << P->info.nim
         << ", Jenis Kelamin: " << P->info.jenis_kelamin
         << ", IPK: " << P->info.ipk << endl;
    P = P->next;
  } while (P != L.first);
}