#include "bstree.h"

address alokasi(infotype x)
{
    address p = new Node;
    if (p != Nil)
    {
        p->info = x;
        p->left = Nil;
        p->right = Nil;
    }
    return p;
}

void insertNode(address &root, infotype x)
{
    if (root == Nil)
    {
        root = alokasi(x);
    }
    else if (x < root->info)
    {
        insertNode(root->left, x);
    }
    else if (x > root->info)
    {
        insertNode(root->right, x);
    }
}

address findNode(infotype x, address root)
{
    if (root == Nil)
    {
        return Nil;
    }
    else if (x == root->info)
    {
        return root;
    }
    else if (x < root->info)
    {
        return findNode(x, root->left);
    }
    else
    {
        return findNode(x, root->right);
    }
}

int hitungJumlahNode(address root)
{
    if (root == Nil)
    {
        return 0;
    }
    else
    {
        return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
    }
}

int hitungTotalInfo(address root, int start)
{
    if (root == Nil)
    {
        return start;
    }
    else
    {
        start += root->info;
        start = hitungTotalInfo(root->left, start);
        start = hitungTotalInfo(root->right, start);
        return start;
    }
}

int hitungKedalaman(address root, int start)
{
    if (root == Nil)
    {
        return start;
    }
    else
    {
        int kiri = hitungKedalaman(root->left, start + 1);
        int kanan = hitungKedalaman(root->right, start + 1);
        return (kiri > kanan) ? kiri : kanan;
    }
}

void printPreorder(address root)
{
    if (root != Nil)
    {
        cout << root->info << " - ";
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

void printPostorder(address root)
{
    if (root != Nil)
    {
        printPostorder(root->left);
        printPostorder(root->right);
        cout << root->info << " - ";
    }
}

void printInorder(address root)
{
    if (root != Nil)
    {
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}