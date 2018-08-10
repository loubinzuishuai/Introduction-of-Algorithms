#include<iostream>
#include<string>
using namespace std;
const int maxn = 100;
int length[maxn][maxn];  //记录最长字串的长度
int memoized_LCS(string &s1, string &s2, int n1, int n2)
{
	if (n1 < 0 || n2 < 0)
		return 0;
	if (length[n1][n2] > 0)
		return length[n1][n2];
	int result = 0;
	if (s1[n1] == s2[n2])
		result = memoized_LCS(s1, s2, n1 - 1, n2 - 1) + 1;
	else
	{
		int result1 = memoized_LCS(s1, s2, n1 - 1, n2);
		int result2 = memoized_LCS(s1, s2, n1, n2 - 1);
		result = result1 >= result2 ? result1 : result2;
	}
	length[n1][n2] = result;
	return result;
}
void print(string &s1, string &s2, int n1, int n2)
{
	if (n1 < 0 || n2 < 0)
		return;
	if (s1[n1] == s2[n2])
	{
		print(s1, s2, n1 - 1, n2 - 1);
		cout << s1[n1];
	}
	else
	{
		if (n1 == 0 && n2 == 0)
			return;
		else if (n1 == 0)
			print(s1, s2, n1, n2 - 1);
		else if (n2 == 0)
			print(s1, s2, n1 - 1, n2);
		else
			length[n1 - 1][n2] >= length[n1][n2 - 1] ? print(s1, s2, n1 - 1, n2) : print(s1, s2, n1, n2 - 1);
	}
}
int main()
{

	while (1)
	{
		string s1, s2;
		cout << "输入两个字符串" << endl;
		cin.sync();		//清空缓冲区
		getline(cin, s1);
		getline(cin, s2);
		for (int i = 0; i < s1.length(); i++)
			for (int j = 0; j < s2.length(); j++)
				length[i][j] = -1;
		int result = memoized_LCS(s1, s2, s1.length()-1, s2.length()-1);
		print(s1, s2, s1.length() - 1, s2.length() - 1);
		cout << endl;
	}
	return 0;
}