#include <iostream>
#include <map>
#include <fstream>
#include <string>
using namespace std;
struct Node
{
	string name;
	Node* left, * right;
	Node(string item)
	{
		name = item;
		left = right = NULL;
	}
	void adoptChild(Node* child1, Node* child2)
	{
		left = child1;
		right = child2;
	}
};
void Preorder(Node* tree)
{
	if (tree == NULL)
		return;
	cout << tree->name << " ";
	Preorder(tree->left);
	Preorder(tree->right);
}
void Inorder(Node* tree)
{
	if (tree == NULL)
		return;
	Inorder(tree->left);
	cout << tree->name << " ";
	Inorder(tree->right);
}
void Postorder(Node* tree)
{
	if (tree == NULL)
		return;
	Postorder(tree->left);
	Postorder(tree->right);
	cout << tree->name << " ";
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
		cout << r->name << "\n ";
		if (r->left)
		{
			for (int i = 0; i < h; i++)
				cout << " ";
			cout << "  \\\n";
			printTree(r->left, h + 3);
		}
	}
}
void read_File(map<string, Node*>& a)
{
	int n;
	fstream file("input.txt", ios::in);
	file >> n;
	bool flag = true;
	while (!file.eof())
	{
		char ch;
		string temp, temp1, temp2, space;
		file >> ch;
		getline(file, temp, ' ');
		Node* k = nullptr;
		if (a.find(temp) == a.end())
			k = new Node(temp);
		else
			k = a.find(temp)->second;
		file >> ch;
		getline(file, temp1, ' ');
		Node* k1 = nullptr;
		if (a.find(temp1) == a.end())
			k1 = new Node(temp1);
		else
			k1 = a.find(temp1)->second;

		getline(file, temp2, ')');
		Node* k2 = nullptr;
		getline(file, space, '\n'); // passby the rest of the line
		if (a.find(temp2) == a.end())
			k2 = new Node(temp2);
		else
			k2 = a.find(temp2)->second;

		k->adoptChild(k1, k2);

		if (a.find(temp) == a.end())
			a.emplace(temp, k);
		if (a.find(temp1) == a.end())
			a.emplace(temp1, k1);
		if (a.find(temp2) == a.end())
			a.emplace(temp2, k2);
	}
	file.close();
}
string get_ancestor()
{
	fstream file("input.txt", ios::in);
	char ch;
	int n;
	file >> n;
	file >> ch;
	string temp;
	getline(file, temp, ' ');
	file.close();
	return temp;
}
int main()
{
	map<string, Node*> a;
	string Ancestor = get_ancestor();
	Node* tree = NULL;
	read_File(a);
	tree = a.find(Ancestor)->second;
	printTree(tree, 0);
	//  Preorder(tree);
	//  Inorder(tree);
	//  Postorder(tree);
}