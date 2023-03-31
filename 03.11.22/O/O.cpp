#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int m, n, g, t, a, b;
	cin >> m >> n >> g >> t;
	int** s = new int* [n];
	int** res = new int* [n];
	pair<int, int>** pr = new pair<int, int>* [n];
	for (int i = 0; i < n; i++)
	{
		s[i] = new int[m];
		res[i] = new int[m];
		pr[i] = new pair<int, int>[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			s[i][j] = 0;
		}
	}
	for (int i = 0; i < g; i++)
	{
		cin >> a >> b;
		s[b - 1][a - 1] = 1;
	}
	for (int i = 0; i < t; i++)
	{
		cin >> a >> b;
		s[b - 1][a - 1] = -1;
	}
	res[0][0] = 0;
	for (int j = 1; j < m; j++)
	{
		if (s[0][j] != -1)
		{
			if (s[0][j - 1] == -1)
			{
				res[0][j] = -1;
			}
			else
			{
				res[0][j] = res[0][j - 1] + s[0][j];
				pr[0][j] = make_pair(0, j - 1);
			}
		}
		else
		{
			res[0][j] = -1;
		}
	}
	for (int i = 1; i < n; i++)
	{
		if (s[i][0] != -1)
		{
			if (s[i - 1][0] != -1)
			{
				res[i][0] = res[i - 1][0] + s[i][0];
				pr[i][0] = make_pair(i - 1, 0);
			}
			else
			{
				res[i][0] = -1;
			}
		}
		else
		{
			res[i][0] = -1;
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (s[i][j] != -1)
			{
				res[i][j] = max(res[i][j - 1], res[i - 1][j]);
				if (res[i][j] == -1)
				{
					res[i][j] = -1;
				}
				else
				{
					if (res[i][j] == res[i][j - 1])
					{
						pr[i][j] = make_pair(i, j - 1);
					}
					else
					{
						pr[i][j] = make_pair(i - 1, j);
					}
					res[i][j] += s[i][j];
				}
			}
			else
			{
				res[i][j] = -1;
			}
		}
	}
	pair<int, int>p = make_pair(n - 1, m - 1);
	pair<int, int>* mas = new pair<int, int>[m + n - 1];
	int k = 0;
	while (p != make_pair(0, 0))
	{
		mas[k] = p;
		k++;
		p = pr[p.first][p.second];
	}
	cout << res[n - 1][m - 1] << endl;
	if (res[n - 1][m - 1] != -1)
	{
		for (int i = m + n - 2; i >= 0; i--)
		{
			cout << mas[i].second + 1 << " " << mas[i].first + 1 << endl;
		}
	}
}