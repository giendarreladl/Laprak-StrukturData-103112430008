#include <iostream>
#include "tree.h"
#include "tree.cpp"

using namespace std;

int main()
{
    BinaryTree tree;

    cout << "=== INSERT DATA ===\n"
         << endl;

    tree.insert(10);
    tree.insert(15);
    tree.insert(20);
    tree.insert(30);
    tree.insert(35);
    tree.insert(40);
    tree.insert(50);

    cout << "data yang diinsert: 10, 15, 20, 30, 35, 40, 50\n"
         << endl;
    cout << "\nTraversal setelah insert: " << endl;
    cout << "Inorder: ";
    tree.inOrder();
    cout << "Preorder: ";
    tree.preOrder();
    cout << "Postorder: ";
    tree.postOrder();

    cout << "\n=== UPDATE DATA ==="
         << endl;
    cout << "sebelum diupdate (20 -> 25): " << endl;
    cout << "Inorder: ";
    tree.inOrder();

    tree.update(20, 25);

    cout << "sesudah diupdate (20 -> 25): " << endl;
    cout << "Inorder: ";
    tree.inOrder();

    cout << "\n=== DELETE DATA ==="
         << endl;
    cout << "sebelum delete (hapus subtree dengan root = 30): " << endl;
    cout << "Inorder: ";
    tree.inOrder();

    tree.deleteValue(30);

    cout << "setelah delete (subtree root = 30 dihapus): " << endl;
    cout << "Inorder: ";
    tree.inOrder();

    return 0;
}