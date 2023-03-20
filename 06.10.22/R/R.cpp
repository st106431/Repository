#include <iostream>
using namespace std;

int mulMod(int a, int b, int m) 
{
	int res = 0;
	for (; b > 0; b >>= 1)
	{
		if (b & 1)
		{
			res = (res + a) % m;
		}
		a = (a + a) % m;
	}
	return res;
}


int** mult(int** m_1, int k, int m)
{
	if (k == 1)
	{
		return m_1;
	}
	int sum;
	int** res = mult(m_1, k - 1, m);
	int** ip = new int* [2];
	for (int i = 0; i < 2; i++)
	{
		ip[i] = new int[2];
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			sum = 0;
			for (int k = 0; k < 2; k++)
			{
				sum = (sum + (mulMod(m_1[i][k], res[k][j], m))) % m;
			}
			ip[i][j] = sum;
		}
	}
	return ip;
}

int main()
{
	int n;
	int m;
	cin >> n >> m;
	int** mx = new int* [2];
	for (int i = 0; i < 2; i++)
	{
		mx[i] = new int[2];
	}
	mx[0][0] = 1;
	mx[0][1] = 1;
	mx[1][0] = 1;
	mx[1][1] = 0;
	mx = mult(mx, n - 1, m);
	cout << mx[0][0];
}
