#include <iostream>
#include <string>
#include <stack>
using namespace std;
const int maxn = 100;
int search(int max_last[], int last_n, string &s, int i)
{
	//在max_last中寻找第一个大于S[i]的位置，并返回
	int low = 1, high = last_n;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (s[i] < s[max_last[mid]])
			high = mid - 1;
		else if (s[i] >= s[max_last[mid]])
			low = mid + 1;
	}
	return low;
}
string LDS(string s)
{
	int max_last[maxn];  //last[i]为当前找到的长度为i的最大末尾的索引。
	int pre[maxn];  //pre[i]表示字符串s中，s[i]的前驱的索引
	max_last[0] = -1;
	pre[0] = -1;
	int last_n = 0; //max_last的长度
	for (int i = 0; i < s.length(); i++)
	{
		int pos = search(max_last, last_n, s, i);
		max_last[pos] = i;
		pre[i] = max_last[pos - 1];
		if (pos > last_n) last_n++;
	}

	stack<int> stk;
	for (int i = max_last[last_n]; i != -1; i = pre[i])
		stk.push(i);
	string result = "";
	while (!stk.empty())
	{
		int k = stk.top();
		stk.pop();
		result += s[k];
	}
	return result;
}
int main()
{
	while (1)
	{
		string s;
		cout << "请输入字符串：" << endl;
		cin >> s;
		string s_sub = LDS(s);
		cout << "最长递减子序列为：" << endl;
		cout << s_sub << endl;
	}
	return 0;
}