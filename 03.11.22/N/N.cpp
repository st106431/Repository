#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;
	int** s = new int* [n];
	int** res = new int* [n];
	for (int i = 0; i < n; i++)
	{
		s[i] = new int[m];
		res[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> s[i][j];
		}
	}
	res[0][0] = 0;
	for (int j = 1; j < m; j++)
	{
		res[0][j] = res[0][j - 1] + abs(s[0][j] - s[0][j - 1]);
	}
	for (int i = 1; i < n; i++)
	{
		res[i][0] = res[i - 1][0] + abs(s[i][0] - s[i - 1][0]);
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			res[i][j] = min(res[i][j - 1] + abs(s[i][j] - s[i][j - 1]), res[i - 1][j] + abs(s[i][j] - s[i - 1][j]));
		}
	}
	cout << res[n - 1][m - 1];
}