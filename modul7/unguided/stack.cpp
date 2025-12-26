#include <iostream>
#include "stack.h"
using namespace std;

void CreateStack(Stack &S)
{
    S.top = -1;
}

void Push(Stack &S, infotype x)
{
    if (S.top < 19)
    {
        S.top++;
        S.info[S.top] = x;
    }
    else
    {
        cout << "Stack penuh!" << endl;
    }
}

infotype Pop(Stack &S)
{
    if (S.top >= 0)
    {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    }
    else
    {
        cout << "Stack kosong!" << endl;
        return -1;
    }
}

void printInfo(Stack S)
{
    if (S.top == -1)
    {
        cout << "Stack kosong!" << endl;
        return;
    }
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--)
    {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S)
{
    Stack Temp;
    CreateStack(Temp);

    while (S.top != -1)
    {
        Push(Temp, Pop(S));
    }

    S = Temp;
}

void pushAscending(Stack &S, infotype x)
{
    if (S.top == 19)
    {
        cout << "Stack penuh!" << endl;
        return;
    }

    Stack Temp;
    CreateStack(Temp);

    // Pindahkan elemen yang lebih besar dari x ke Temp
    while (S.top != -1 && S.info[S.top] > x)
    {
        Push(Temp, Pop(S));
    }

    // Masukkan x
    Push(S, x);

    // Kembalikan elemen dari Temp
    while (Temp.top != -1)
    {
        Push(S, Pop(Temp));
    }
}