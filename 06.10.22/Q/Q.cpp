#include <iostream>
using namespace std;

int main()
{
	int p, q, r, sum;
	cin >> p >> q >> r;
	int** m_1 = new int*[p];
	int** m_2 = new int*[q];
	int** res = new int* [p];
	for (int i = 0; i < p; i++)
	{
		m_1[i] = new int[q];
		res[i] = new int[r];
	}
	for (int i = 0; i < q; i++)
	{
		m_2[i] = new int[r];
	}
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < q; j++)
		{
			cin >> m_1[i][j];
		}
	}
	for (int i = 0; i < q; i++)
	{
		for (int j = 0; j < r; j++)
		{
			cin >> m_2[i][j];
		}
	}
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < r; j++)
		{
			sum = 0;
			for (int k = 0; k < q; k++)
			{
				sum += m_1[i][k] * m_2[k][j];
			}
			res[i][j] = sum;
		}
	}
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < r; j++)
		{
			if (j != r - 1)
			{
				cout << res[i][j] << " ";
			}
			else
			{
				cout << res[i][j] << endl;
			}
		}
	}
}