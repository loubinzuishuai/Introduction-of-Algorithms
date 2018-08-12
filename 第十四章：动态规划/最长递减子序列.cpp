#include <iostream>
#include <string>
#include <stack>
using namespace std;
const int maxn = 100;
int search(int max_last[], int last_n, string &s, int i)
{
	//��max_last��Ѱ�ҵ�һ������S[i]��λ�ã�������
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
	int max_last[maxn];  //last[i]Ϊ��ǰ�ҵ��ĳ���Ϊi�����ĩβ��������
	int pre[maxn];  //pre[i]��ʾ�ַ���s�У�s[i]��ǰ��������
	max_last[0] = -1;
	pre[0] = -1;
	int last_n = 0; //max_last�ĳ���
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
		cout << "�������ַ�����" << endl;
		cin >> s;
		string s_sub = LDS(s);
		cout << "��ݼ�������Ϊ��" << endl;
		cout << s_sub << endl;
	}
	return 0;
}