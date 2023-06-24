#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

int main()
{
    ifstream f;
    f.open("input1.txt");
    int countWord = 0;
    int countSentence = 0;
    string str, ans;
    while (!f.eof())
    {
        getline(f, str, '\n');
        ans += str + '\n';
        
    }
    cout << ans<<endl;
   

    
    for(int i=0;i<ans.length();i++)
    {
        if (ans[i] == ' ' || ans[i] == '\n')
        {
            countSentence++;
        }
        if (ans[i] == '.' || ans[i] == '?' || ans[i] == '!')
        {
            countWord++;
        }
    }
    cout << "Number of words in file are " << countWord<<endl;
    cout << "Number of sentences in file are " << countSentence<<endl;
    f.close();
    return 0;
}