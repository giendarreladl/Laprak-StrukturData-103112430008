#include <iostream>
#include "bstree.h"
#include "bstree.cpp"

using namespace std;

int main()
{
    cout << "Hello World" << endl;

    address root = Nil;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 7);

    cout << "Inorder Traversal: ";
    printInorder(root);
    cout << endl;

    cout << "kedalaman : " << hitungKedalaman(root, 0) << endl;
    cout << "jumlah Node : " << hitungJumlahNode(root) << endl;
    cout << "total : " << hitungTotalInfo(root, 0) << endl;

    cout << "\nPre-order  : ";
    printPreorder(root);
    cout << endl;

    cout << "Post-order : ";
    printPostorder(root);
    cout << endl;

    return 0;
}