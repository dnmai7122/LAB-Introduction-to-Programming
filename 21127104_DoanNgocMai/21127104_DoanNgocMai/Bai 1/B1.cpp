#include"HeaderB1.h"
int main()
{
	int a[100];
	int n;
	int l = 0;
	
	do {
		cout << "Nhap so phan tu: ";
		cin >> n;
	} while (n < 0);
	int r = n;
	int aux[100];
	input(a, n);
	int ch;
	cout << "\n==MENU==";
	cout << "\n1. Quicksort"
		<< "\n2.Mergesort";
	cout << "\nEnter your choice: ";
	cin >> ch;
	switch (ch)
	{
	case 1:
		quicksort(a, l, r);
		reserve(a, n);
	case 2:
		mergesort(a, aux, l, r);
		reserve(a, n);
	}
	
}