#include <iostream>
#include <string>
using namespace std;
const int maxn = 100;
int length[maxn][maxn];		//length[i][j]表示第一个串长度为i的子串和第二个串长度为j的子串的最长公共子串的长度
int choice[maxn][maxn];		//choice[i][j]等于0表示x[i] = y[j],然后求x[i-1]和y[j-1]的LCS；等于1表示x[i]不等于y[j]，然后求x[i-1]和y[j]的LCS；等于2表示表示x[i]不等于y[j]，然后求x[i]和y[j-1]的LCS
void LCS(string s1, string s2)
{
	//c语言中string下标是从0开始的，在代码中索引字母时候做一下转换，用1表示第一个字符串起始索引
	int length_1 = s1.length();
	int length_2 = s2.length();
	for (int i = 0; i <= length_1; i++)
		length[i][0] = 0;
	for (int i = 0; i <= length_2; i++)
		length[0][i] = 0;
	for (int i = 1; i <= length_1; i++)
		for (int j = 1; j <= length_2; j++)
			if (s1[i - 1] == s2[j - 1]) //减一的目的正是因为索引变换了
			{
				length[i][j] = length[i - 1][j - 1] + 1;
				choice[i][j] = 0;
			}
			else if (length[i - 1][j] >= length[i][j - 1])
			{
				length[i][j] = length[i - 1][j];
				choice[i][j] = 1;
			}
			else
			{
				length[i][j] = length[i][j - 1];
				choice[i][j] = 2;
			}
		
}
void print(string s1, string s2, int n1, int n2)
{
	if (n1 == 0 || n2 == 0)
		return;
	if (s1[n1 - 1] == s2[n2 - 1])
	{
		print(s1, s2, n1 - 1, n2 - 1);
		cout << s1[n1 - 1];
	}
	else if (length[n1 - 1][n2] >= length[n1][n2 - 1])
		print(s1, s2, n1 - 1, n2);
	else
		print(s1, s2, n1, n2 - 1);
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
		LCS(s1, s2);
		print(s1, s2, s1.length() + 1, s2.length() + 1);
		cout << endl;
	}
	return 0;
}