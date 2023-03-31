#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	cin >> n;
	int* s_1 = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> s_1[i];
	}
	cin >> m;
	int* s_2 = new int[m];
	for (int i = 0; i < m; i++)
	{
		cin >> s_2[i];
	}
	int** s = new int* [n];
	for (int i = 0; i < n; i++)
	{
		s[i] = new int[m];
	}
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		count = 0;
		for (int j = 0; j <= i; j++)
		{
			if (s_2[0] == s_1[j])
			{
				count++;
			}
		}
		if (count > 0)
		{
			s[i][0] = 1;
		}
		else
		{
			s[i][0] = 0;
		}
	}
	for (int i = 0; i < m; i++)
	{
		count = 0;
		for (int j = 0; j <= i; j++)
		{
			if (s_1[0] == s_2[j])
			{
				count++;
			}
		}
		if (count > 0)
		{
			s[0][i] = 1;
		}
		else
		{
			s[0][i] = 0;
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			s[i][j] = max(s[i][j - 1], s[i - 1][j]);
			if (s_1[i] == s_2[j])
			{
				s[i][j] = max(s[i][j], s[i - 1][j - 1] + 1);
			}
		}
	}
	cout << s[n - 1][m - 1];
}
