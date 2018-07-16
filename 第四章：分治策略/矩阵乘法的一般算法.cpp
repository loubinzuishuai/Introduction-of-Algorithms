#include <iostream>
using namespace std;
class Matrix
{
public:
	int n, m;    //n行m列
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
		cout << "无法相乘" << endl;
}
int main()
{
	while (1)
	{
		cout << "输入第一个矩阵的行和列：" << endl;
		int n, m;
		cin >> n >> m;
		cout << "输入第一个矩阵：" << endl;
		Matrix m1;
		m1.n = n; m1.m = m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> m1.A[i][j];

		cout << "输入第二个矩阵的行和列：" << endl;
		cin >> n >> m;
		cout << "输入第二个矩阵：" << endl;
		Matrix m2;
		m2.n = n; m2.m = m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> m2.A[i][j];

		Matrix m3;
		matrix_multiply_ordinary(m1, m2, m3);
		cout << "矩阵乘积为：" << endl;
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