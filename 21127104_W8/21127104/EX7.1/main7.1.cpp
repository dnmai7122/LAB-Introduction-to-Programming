#include"Header7.1.h"
int main()
{
    Node* root = NULL;

    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);
    root = insertNode(root, 99);
    root = insertNode(root, 100);
    root = insertNode(root, 77);
    root = insertNode(root, 7);
    cout << "\nBefore Delete: \n";
    int h = height(root);
    printTree(root, h);
    cout << "\nPreOrd \n";
    preOrder(root);
    cout << "\nInOrd \n";
    inOrder(root);
    cout << "\nPostOrd \n";
    postOrder(root);
    deleteNode(root, 40);
    deleteNode(root, 10);
    cout << "\nAfter Delete: \n";
    h = height(root);
    printTree(root, h);



   

    return 0;
}
