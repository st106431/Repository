#include <iostream>
using namespace std;

int main()
{
	int n, m, a, b;
	cin >> n >> m;
	int** s = new int* [n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		s[i] = new int[n + 1];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			s[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		s[a][b] = 1;
		s[b][a] = 1;
	}
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; (j <= n) && (j != i); j++)
		{
			for (int k = 1; (k <= n) && (k != i) && (k != j); k++)
			{
				if (s[i][j] == 1 && s[j][k] == 1 && s[i][k] == 1)
				{
					count++;
				}
			}
		}
	}
	cout << count;
}