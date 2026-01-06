#include "doublylist.h"

void CreateList(List &L) {
    L.First = NULL;
    L.Last = NULL;
}

address alokasi(infotype X) {
    address P = new ElmList;
    P->info = X;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}


void printInfo(List L) {
    if (L.First == NULL) {
        cout << "List kosong" << endl;
        return;
    }

    address P = L.First;
    while (P != NULL) {
        cout << "nopol : " << P->info.nopol << endl;
        cout << "warna : " << P->info.warna << endl;
        cout << "tahun : " << P->info.thnBuat << endl;
        cout << endl;
        P = P->next;
    }
}


void insertLast(List &L, address P) {
    if (L.First == NULL) {
        L.First = P;
        L.Last = P;
    } else {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}


address findElm(List L, string nopol) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}


bool isNopolExist(List L, string nopol) {
    return findElm(L, nopol) != NULL;
}


void deleteFirst(List &L, address &P) {
    if (L.First == NULL) {
        P = NULL;
        return;
    }

    P = L.First;
    if (L.First == L.Last) {
        L.First = NULL;
        L.Last = NULL;
    } else {
        L.First = L.First->next;
        L.First->prev = NULL;
    }

    P->next = NULL;
    P->prev = NULL;
}


void deleteLast(List &L, address &P) {
    if (L.Last == NULL) {
        P = NULL;
        return;
    }

    P = L.Last;
    if (L.First == L.Last) {
        L.First = NULL;
        L.Last = NULL;
    } else {
        L.Last = L.Last->prev;
        L.Last->next = NULL;
    }

    P->prev = NULL;
}


void deleteAfter(address Prec, address &P) {
    if (Prec == NULL || Prec->next == NULL) {
        P = NULL;
        return;
    }

    P = Prec->next;
    Prec->next = P->next;
    if (P->next != NULL) {
        P->next->prev = Prec;
    }

    P->next = NULL;
    P->prev = NULL;
}


bool deleteByNopol(List &L, string nopol) {
    address P = findElm(L, nopol);
    if (P == NULL) {
        return false; 
    }

    address deletedNode;
    if (P == L.First) {
        deleteFirst(L, deletedNode);
        dealokasi(deletedNode);
    } else if (P == L.Last) {
        deleteLast(L, deletedNode);
        dealokasi(deletedNode);
    } else {
        deleteAfter(P->prev, deletedNode);
        dealokasi(deletedNode);
    }

    return true;
}