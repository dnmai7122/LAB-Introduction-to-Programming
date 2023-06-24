#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
#define MAX 100
void linearSearch(int a[], int n, int x, ofstream& fileout)
{
	
	for (int i = 0; i < n; i++)
	{
		
		if (a[i] == x) 
		{
			/*int j = 0;
			while (a[i] == x)
			{
				b[j] = i;
				j++;
				
			}*/
			fileout << i;
		}
	}
	
}
int  sentinelLinearSearch(int a[], int n, int x)
{
	int last = a[n - 1];
	a[n - 1] = x;
	int i = 0;
	while (a[i] != x)
	{
		i++;
	}
	a[n - 1] = last;
	if ((i < n - 1) || (x == a[n - 1]))
	{
		return i;
	}
	else
	{
		return -1;
	}
}
int partition(int a[], int l, int r) 
{
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
int isSorted(int a[], int n, int x)
{
	int flag=0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n-1; j++)
		{
			if (a[i] > a[j])
				flag++;
		}
	}
	return flag;
}
int binarySearch(int a[], int l, int r, int x)
{
	int flag = isSorted(a, r, x);
	if (flag != 0){
		quicksort(a, l, r);
	}
	if (r >= l)
	{
		int mid = l + (r - l) / 2;

		if (a[mid] == x)
			return mid;


		if (a[mid] > x)
			return binarySearch(a, l, mid - 1, x);


		return binarySearch(a, mid + 1, r, x);
	}
	return -1;
}

int main(int argc, char* argv[])
{
	string s1, s2;
	int a[MAX];
	int n = 0;
	int x = 0;
	ifstream filein;
	ofstream fileout;
	s1 = argv[3];
	s2 = argv[4];
	int ch = atoi(argv[1]);
	x = atoi(argv[2]);
	filein.open(s1);
	fileout.open(s2);
	filein >> n;
	for (int i = 0; i < n; i++)
		filein >> a[i];
	if (ch == 1)
		linearSearch(a, n, x, fileout);
	else if (ch == 2)
		fileout << sentinelLinearSearch(a, n, x);
	else if (ch == 3)
		fileout << binarySearch(a, 0, n, x);
	else fileout << "Invalid choice";
	filein.close();
	fileout.close();
	
	/*int idx = linearSearch(a, n, atoi(argv[2]));*/
	
	
	return 0;
	
}