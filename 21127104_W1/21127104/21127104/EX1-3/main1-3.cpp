#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() 
{
	ifstream fin;
	ofstream fout;
	float temp[1000][12];
	int n;
	string s, ans;
	fin.open("input1.3.txt");
	fout.open("output1.3.txt");
	fin >> n;
	getline(fin, s, '\n');
	while (!fin.eof())
	{
		getline(fin, s, '\n');
		ans += s + '\n';
	}
	string n1;
	float n2;
	int k = 0, j = 0;
	for (int i = 0; i < ans.length(); i++)
	{
		n1 += ans[i];
		if (ans[i] == ' ')
		{
			n2 = stof(n1);
			temp[k][j] = n2;
			j++;
			n1 = "";
		}
		if (ans[i] == '\n')
		{
			n2 = stof(n1);
			temp[k][j] = n2;
			k++;
			j = 0;
			n1 = "";
		}
	}
	for (int i = 0; i < n; i++)
	{
		float min = temp[i][0], max = temp[i][0], at = 0;
		for (int j = 0; j < 12; j++)
		{
			if (temp[i][j] > max)
				max = temp[i][j];
			if (temp[i][j] < min)
				min = temp[i][j];
			at += temp[i][j];
		}
		fout << "Day " << i + 1 << ":\t  average temperature: " << at / 12;
		fout << "\thigh temperature: " << max;
		fout << "\tlow temperature: " << min << endl;
	}
	fin.close();
	fout.close();
}