#pragma once
#include<iostream>
#include<string>
using namespace std;
struct Node {
    int data;
    Node* link;
};
Node* top;
void push(int data)
{
    Node* temp = new Node();
    if (!temp)
    {
        cout << "\nOverflow";
        exit(1);
    }
    temp->data = data;
    temp->link = top;
    top = temp;
}
int isEmpty()
{
    return top == NULL;
}
void pop()
{
    Node* temp;

    if (top == NULL)
    {
        cout << "\nStack Underflow" << endl;
        exit(1);
    }
    else
    {
        temp = top;
        top = top->link;
        free(temp);
    }
}
void display()
{
    Node* temp;

    if (top == NULL)
    {
        cout << "\nUnderflow";
        exit(1);
    }
    else
    {
        temp = top;
        while (temp != NULL)
        {
            cout << temp->data << "-> ";
            temp = temp->link;
        }
    }
}

int displayMemory()
{
    int count = 0;
    Node* current = top;
    while (current != NULL)
    {
        count += sizeof(current);
        current = current->link;
    }
    return count;
}