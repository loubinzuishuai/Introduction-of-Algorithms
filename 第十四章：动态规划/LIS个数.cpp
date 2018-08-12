#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int maxn = 100;
vector<int> pre[maxn];   //pre[i]中存有一系列整数，这些整数是以i为末尾的最长递增子序列的前驱的索引
void print(string s, int k, int n, string result)
{
	//输出以k为末尾的长度为n的子序列， 字符串result是后继字符串，当n为0时打印result
	if (n == 0 || k == -1)
	{
		for (int i = result.length() - 1; i >= 0; i--)
			cout << result[i];
		cout << endl;
	}
	else
	{
		result += s[k];
		for (int i = 0; i < pre[k].size(); i++)
			print(s, pre[k].at(i), n - 1, result);
	}
	
}
void number_of_LIS(string s)
{
	//初始化容器，这一步很容易忘记啊
	for (int i = 0; i < s.length(); i++)
		pre[i].clear();
	int length[maxn];  //length[i]表示以字符s[i]结尾的最长递增子序列的长度
	length[0] = 1;
	pre[0].push_back(-1);
	int max = 1;   //最长递增子序列的长度
	for (int i = 1; i < s.length(); i++)
	{
		// 遍历序列0-i找到以i为末尾的最长递增子序列的长度。
		length[i] = 1;
		for (int j = 0; j < i; j++)
			if (s[j] < s[i])
			{
				int len = length[j] + 1;
				if (len > length[i])
					length[i] = len;
			}
		
		for (int j = 0; j < i; j++)
			if (length[j] == length[i] - 1 && s[j] < s[i])
				pre[i].push_back(j);
		if (length[i] == 1)
			pre[i].push_back(-1); //-1作为边界条件，表示以i为末尾的最长递增子序列是1
		if (max < length[i])
			max = length[i];
	}
	for (int i = 0; i < s.length(); i++)
	{
		string result = "";
		if (length[i] == max)
			print(s, i, max, result);
	}
}
int main()
{
	while (1)
	{
		string s;
		cout << "请输入字符串：" << endl;
		cin >> s;
		number_of_LIS(s);
	}
	return 0;
}