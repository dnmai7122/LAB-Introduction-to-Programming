#include"Header1-1.h"

int main()
{
	int a[10000];
	int aux[10000];
	int a1[10000];
	int a2[10000];
	int l = 0, r = 10000;
	int n = 10000;

	for (int i = 0; i < 10000; i++)
	{
		a[i] = rand() % 10000+1;
		a1[i] = a[i];
		a2[i] = a[i];
	}


	//insertion sort

	auto start = high_resolution_clock::now();
	insertion(a, l, r);
	cout << endl;
	cout << endl;
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);
	cout << "\nTime taken by function insertion sort: "
		<< duration.count() << " milliseconds" << endl;

	//merge sort

	auto start1 = high_resolution_clock::now();
	mergesort(a1, aux, l, r);
	
	cout << endl;
	auto stop1 = high_resolution_clock::now();
	auto duration1 = duration_cast<milliseconds>(stop1 - start1);
	cout << "\nTime taken by function merge sort: "
		<< duration1.count() << " milliseconds" << endl;

	//quick sort

	auto start2 = high_resolution_clock::now();
	quicksort(a2,l,r);
	cout << endl;
	auto stop2 = high_resolution_clock::now();
	auto duration2 = duration_cast<milliseconds>(stop2 - start2);
	cout << "\nTime taken by function quick sort: "
		<< duration2.count() << " milliseconds" << endl;

	return 0;
}