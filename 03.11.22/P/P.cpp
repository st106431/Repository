#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string a, b;
	cin >> a;
	cin >> b;
	int l, r;
	l = a.length();
	r = b.length();
	int** s = new int* [l + 1];
	for (int i = 0; i < l + 1; i++)
	{
		s[i] = new int[r + 1];
	}
	s[0][0] = 0;
	s[0][1] = 1;
	s[1][0] = 1;
	for (int i = 0; i < l + 1; i++)
	{
		s[i][0] = i;
	}
	for (int i = 0; i < r + 1; i++)
	{
		s[0][i] = i;
	}
	for (int i = 1; i <= l; i++)
	{
		for (int j = 1; j <= r; j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				s[i][j] = s[i - 1][j - 1];
			}
			else
			{
				s[i][j] = min(min(s[i - 1][j], s[i][j - 1]), s[i - 1][j - 1]);
				s[i][j]++;
			}
		}
	}
	cout << s[l][r];
}