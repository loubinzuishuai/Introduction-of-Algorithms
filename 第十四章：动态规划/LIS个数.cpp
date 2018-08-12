#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int maxn = 100;
vector<int> pre[maxn];   //pre[i]�д���һϵ����������Щ��������iΪĩβ������������е�ǰ��������
void print(string s, int k, int n, string result)
{
	//�����kΪĩβ�ĳ���Ϊn�������У� �ַ���result�Ǻ���ַ�������nΪ0ʱ��ӡresult
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
	//��ʼ����������һ�����������ǰ�
	for (int i = 0; i < s.length(); i++)
		pre[i].clear();
	int length[maxn];  //length[i]��ʾ���ַ�s[i]��β������������еĳ���
	length[0] = 1;
	pre[0].push_back(-1);
	int max = 1;   //����������еĳ���
	for (int i = 1; i < s.length(); i++)
	{
		// ��������0-i�ҵ���iΪĩβ������������еĳ��ȡ�
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
			pre[i].push_back(-1); //-1��Ϊ�߽���������ʾ��iΪĩβ���������������1
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
		cout << "�������ַ�����" << endl;
		cin >> s;
		number_of_LIS(s);
	}
	return 0;
}