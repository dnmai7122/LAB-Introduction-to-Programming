#include"Header7.1.h";
int size(Node* N)
{
    if (N == NULL)
    {
        return 0;
    }
    return N->size;
}
int height(Node* N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
int max(int a, int b)
{
    return (a > b) ? a : b;
}
Node* newNode(int key)
{
    Node* newNode = new Node();
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;

    return(newNode);
}
Node* RR_Rotate(Node* root)
{
    Node* temp;
    temp = root->right;
    root->right = temp->left;
    temp->left = root;
    return temp;
}
Node* LL_Rotate(Node* root)
{
    Node* temp;
    temp = root->left;
    root->left = temp->right;
    temp->right = root;
    return temp;
}
Node* LR_Rotate(Node* root)
{
    Node* temp;
    temp = root->left;
    root->left = RR_Rotate(temp);
    return LL_Rotate(root);
}
Node* RL_Rotate(Node* root)
{
    Node* temp;
    temp = root->right;
    root->right = LL_Rotate(temp);
    return RR_Rotate(root);
}
Node* balance(Node* r)
{
    int h = height(r);
    if (h > 1)
    {
        if (height(r->left) > 0)
            r = LL_Rotate(r);
        else
            r = LR_Rotate(r);
    }
    else if (h < -1)
    {
        if (height(r->right) > 0)
            r = RL_Rotate(r);
        else r = RR_Rotate(r);
    }
    return r;
}
Node* insertNode(Node* r, int key)
{
    if (r == NULL)
    {
        r = new Node();
        r->key = key;
        r->left = NULL;
        r->right = NULL;
        return r;
    }
    else if (key < r->key)
    {
        r->left = insertNode(r->left, key);
        r = balance(r);
    }
    else if (key >= r->key)
    {
        r->right = insertNode(r->right, key);
        r = balance(r);
    }
    return r;
}
void printTree(Node* tree, int h)
{
    Node* r = tree;
    if (r == nullptr)
    {
        for (int i = 0; i < h; i++)
            cout << " ";
        cout << "*" << endl;
    }
    else
    {
        if (r->right)
            printTree(r->right, h + 3);
        for (int i = 0; i < h; i++)
            cout << " ";
        cout << " ";
        if (r->right)
        {
            cout << " /\n";
            for (int i = 0; i < h; i++)
                cout << " ";
            cout << " ";
        }
        cout << r->key << "\n ";
        if (r->left)
        {
            for (int i = 0; i < h; i++)
                cout << " ";
            cout << "  \\\n";
            printTree(r->left, h + 3);
        }
    }
}
void preOrder(Node* root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(Node* root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}
void postOrder(Node* root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->key << " ";
    }
}
Node* minVal(Node* r)
{
    while (r->left != NULL)
    {
        return minVal(r->left);
    }
    return r;
}
Node* deleteNode(Node* r, int key)
{
    Node* t;
    if (r == NULL)
    {
        return NULL;
    }
    else {
        if (key > r->key)
        {
            r->right = deleteNode(r->right, key);
            r = balance(r);
        }
        if (key < r->key)
        {
            r->left = deleteNode(r->left, key);
            r = balance(r);
        }
        else {
            if (r->right != NULL)
            {
                t = r->right;
                while (t->left != NULL)
                    t = t->left;
                r->key = t->key;
                r->right = deleteNode(r->right, t->key);
                r = balance(r);
            }
            else
                return (r->left);
        }
        r->height = height(r);
        return(r);
    }
}
void find_Val(Node* root, int key)
{
    if (root != NULL)
    {
        if (root->key == key)
        {
            cout << "\nYES";
        }
        else if (root->key < key)
        {
            find_Val(root->right, key);
        }
        else
        {
            find_Val(root->left, key);
        }
    }
    cout << "\nEMPTY";
}
