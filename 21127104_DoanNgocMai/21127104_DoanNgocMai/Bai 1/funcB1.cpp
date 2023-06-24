#include"HeaderB1.h"
void input(int a[], int n)
{
	for (int i = 0; i <= n; i++)
	{
		cout << "a[" << i << "]: ";
		cin >> a[i];
	}
}
void printArr(int a[], int n)
{
	for (int i = 0; i <= n; i++)
	{
		cout << a[i] << " ";
	}
}
void insertion(int a[], int l, int r) {
	int v;
	for (int i = l + 1; i <= r; i++) {
		v = a[i];
		int j;
		for (j = i; j > l && v < a[j - 1]; j--)
			a[j] = a[j - 1];
		a[j] = v;
	}
}

void merge(int a[], int aux[], int l, int m, int r) {
	int i, j, k;
	for (k = l; k <= r; k++)
		aux[k] = a[k];
	i = l; j = m + 1; k = l;
	while (i <= m && j <= r)
		if (aux[i] <= aux[j]) a[k++] = aux[i++];
		else a[k++] = aux[j++];
	while (i <= m)
		a[k++] = aux[i++];
	while (j <= r)
		a[k++] = aux[j++];
}

void mergesort(int a[], int aux[], int l, int r)
{
	if (r <= l) return;
	int m = (l + r) / 2;
	mergesort(a, aux, l, m);
	mergesort(a, aux, m + 1, r);
	merge(a, aux, l, m, r);
}

int partition(int a[], int l, int r) {
	int i = l - 1, j = r; int v = a[r];
	for (;;) {
		while (a[++i] < v);
		while (v < a[--j]) if (j == l) break;
		if (i >= j) break;
		swap(a[i], a[j]);
	}
	swap(a[i], a[r]);
	return i;
}

void quicksort(int a[], int l, int r)
{
	if (r <= l) return;
	int i = partition(a, l, r);
	quicksort(a, l, i - 1);
	quicksort(a, i + 1, r);
}
void reserve(int a[], int n)
{
	for (int i = n; i > 0; i--)
	{
		cout << a[i] << " ";
	}
}
void choice1(int a[],int l, int r)
{
	quicksort(a, l, r);
	reserve(a, n);
}
void choice2(int b[], int l, int r)
{
	mergesort(a, aux, l, r);
	reserve(a, n);
}

