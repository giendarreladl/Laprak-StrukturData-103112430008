#ifndef STACK_H
#define STACK_H

typedef int infotype;

struct Stack
{
    infotype info[20];
    int top;
};

void CreateStack(Stack &S);
void Push(Stack &S, infotype x);
infotype Pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

void pushAscending(Stack &S, infotype x);

#endif