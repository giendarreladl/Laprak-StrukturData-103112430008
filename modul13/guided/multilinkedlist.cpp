#include "multilinkedlist.h"
#include <iostream>
using namespace std;

ParentNode *createParent(string info) {
    ParentNode *p = new ParentNode;
    p->info = info;
    p->childHead = NULL;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

ChildNode *createChild(string info) {
    ChildNode *c = new ChildNode;
    c->info = info;
    c->next = NULL;
    c->prev = NULL;
    return c;
}

void insertParent(ParentNode *&head, string info) {
    ParentNode *newNode = createParent(info);
    if (head == NULL) {
        head = newNode;
    } else {
        ParentNode *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void insertChild(ParentNode *head, string parentInfo, string childInfo) {
    ParentNode *p = head;
    while (p != NULL && p->info != parentInfo)
        p = p->next;

    if (p != NULL) {
        ChildNode *newChild = createChild(childInfo);
        if (p->childHead == NULL) {
            p->childHead = newChild;
        } else {
            ChildNode *c = p->childHead;
            while (c->next != NULL)
                c = c->next;
            c->next = newChild;
            newChild->prev = c;
        }
    }
}

void updateParent(ParentNode *head, string oldInfo, string newInfo) {
    while (head != NULL) {
        if (head->info == oldInfo) {
            head->info = newInfo;
            return;
        }
        head = head->next;
    }
}

void updateChild(ParentNode *head, string parentInfo,
                 string oldChildInfo, string newChildInfo) {
    while (head != NULL && head->info != parentInfo)
        head = head->next;

    if (head != NULL) {
        ChildNode *c = head->childHead;
        while (c != NULL) {
            if (c->info == oldChildInfo) {
                c->info = newChildInfo;
                return;
            }
            c = c->next;
        }
    }
}

void deleteChild(ParentNode *head, string parentInfo, string childInfo) {
    while (head != NULL && head->info != parentInfo)
        head = head->next;

    if (head != NULL) {
        ChildNode *c = head->childHead;
        while (c != NULL) {
            if (c->info == childInfo) {
                if (c == head->childHead) {
                    head->childHead = c->next;
                    if (head->childHead != NULL)
                        head->childHead->prev = NULL;
                } else {
                    c->prev->next = c->next;
                    if (c->next != NULL)
                        c->next->prev = c->prev;
                }
                delete c;
                return;
            }
            c = c->next;
        }
    }
}

void deleteParent(ParentNode *&head, string info) {
    ParentNode *p = head;
    while (p != NULL) {
        if (p->info == info) {
            ChildNode *c = p->childHead;
            while (c != NULL) {
                ChildNode *temp = c;
                c = c->next;
                delete temp;
            }

            if (p == head) {
                head = p->next;
                if (head != NULL)
                    head->prev = NULL;
            } else {
                p->prev->next = p->next;
                if (p->next != NULL)
                    p->next->prev = p->prev;
            }
            delete p;
            return;
        }
        p = p->next;
    }
}

void printAll(ParentNode *head) {
    while (head != NULL) {
        cout << head->info;
        ChildNode *c = head->childHead;
        while (c != NULL) {
            cout << " -> " << c->info;
            c = c->next;
        }
        cout << endl;
        head = head->next;
    }
}
