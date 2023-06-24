#pragma once
#include<iostream>
using namespace std;
struct Node
{
    int key;
    Node* left;
    Node* right;
    int height;
    int size;
};
int size(Node* N);
int height(Node* N);
int max(int a, int b);
Node* newNode(int key);
Node* RR_Rotate(Node* root);
Node* LL_Rotate(Node* root);
Node* LR_Rotate(Node* root);
Node* RL_Rotate(Node* root);
Node* balance(Node* r);
Node* insertNode(Node* r, int key);
void printTree(Node* tree, int h);
void preOrder(Node* root);
void inOrder(Node* root);
void postOrder(Node* root);
Node* minVal(Node* r);
Node* deleteNode(Node* r, int key);
void find_Val(Node* root, int key);
