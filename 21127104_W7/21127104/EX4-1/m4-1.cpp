#include"Header4-1.h"
int main()
{
    Node* head = NULL;
    push(11);
    push(22);
    push(33);
    push(44);
    display();
    pop();
    pop();
    display();
    cout << "\nMemory: " << displayMemory();
    return 0;
}