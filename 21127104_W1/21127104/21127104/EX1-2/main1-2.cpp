#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int UCLN(int a, int b)
{
	if (a % b == 0) return b;
	else return UCLN(b, a % b);
}
struct PS
{
	int tu;
	int mau;
};
//void Irreducible(PS p[])
//{
//	int temp = UCLN(abs(a.tu), abs(a.mau));
//	p.tu /= temp;
//	p.mau /= temp;
//	return a;
//}
int main()
{
	PS p[100];
	fstream file;
	file.open("input2.txt");
	int row, col;
	file >> row;
	file >> col;
	char s;
	for (int i = 0; i < row * col; i++)
	{
		file >> p[i].tu;
		file >> s;
		file >> p[i].mau;
	}
	for (int i = 0; i < row * col; i++)
	{
		int h = UCLN(abs(p[i].tu), abs(p[i].mau));
		if (h != 1) 
		{
			p[i].tu /= h;
			p[i].mau /= h;
		}
	}
	fstream f;
	f.open("output2.txt");
	int r = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			f << p[r].tu << "/" << p[r].mau << " ";
			r++;
		}
		f << endl;
	}
	f.close();
	file.close();
	return 0;
}