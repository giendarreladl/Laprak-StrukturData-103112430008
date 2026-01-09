#ifndef MULTILINKEDLIST_H
#define MULTILINKEDLIST_H

#include <string>
using namespace std;

struct ChildNode {
    string info;
    ChildNode *next;
    ChildNode *prev;
};

struct ParentNode {
    string info;
    ChildNode *childHead;
    ParentNode *next;
    ParentNode *prev;
};

ParentNode *createParent(string info);
ChildNode *createChild(string info);

void insertParent(ParentNode *&head, string info);
void insertChild(ParentNode *head, string parentInfo, string childInfo);

void updateParent(ParentNode *head, string oldInfo, string newInfo);
void updateChild(ParentNode *head, string parentInfo,
                 string oldChildInfo, string newChildInfo);

void deleteParent(ParentNode *&head, string info);
void deleteChild(ParentNode *head, string parentInfo, string childInfo);

void printAll(ParentNode *head);

#endif
