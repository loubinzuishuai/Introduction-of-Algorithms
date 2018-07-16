#include <iostream>
using namespace std;
class Matrix
{
public:
	int n, m;    //n��m��
	double A[100][100];
};
void matrix_multiply_ordinary(Matrix &m1, Matrix &m2, Matrix &m3)
{
	if (m1.m == m2.n)
	{
		for (int i = 0; i < m1.n; i++)
			for (int j = 0; j < m2.m; j++)
			{
				m3.A[i][j] = 0;
				for (int k = 0; k < m1.m; k++)
					m3.A[i][j] += m1.A[i][k] * m2.A[k][j];
			}
		m3.n = m1.n;
		m3.m = m2.m;
	}
	else
		cout << "�޷����" << endl;
}
int main()
{
	while (1)
	{
		cout << "�����һ��������к��У�" << endl;
		int n, m;
		cin >> n >> m;
		cout << "�����һ������" << endl;
		Matrix m1;
		m1.n = n; m1.m = m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> m1.A[i][j];

		cout << "����ڶ���������к��У�" << endl;
		cin >> n >> m;
		cout << "����ڶ�������" << endl;
		Matrix m2;
		m2.n = n; m2.m = m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> m2.A[i][j];

		Matrix m3;
		matrix_multiply_ordinary(m1, m2, m3);
		cout << "����˻�Ϊ��" << endl;
		for (int i = 0; i < m3.n; i++)
		{
			for (int j = 0; j < m3.m; j++)
			{
				cout << m3.A[i][j] << " " ;
			}
			cout << endl;
		}
		
	}
	return 0;
}