#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string a, b;
	getline(cin, a, '\n');
	getline(cin, b, '\n');
	int l = a.length();
	int r = b.length();
	if (l == 0)
	{
		if (r == 0)
		{
			cout << "YES";
			return 0;
		}
		else
		{
			cout << "NO";
			return 0;
		}
	}
	if (r == 0)
	{
		for (int i = 0; i < l; i++)
		{
			if (a[i] != '*')
			{
				cout << "NO";
				return 0;
			}
		}
		cout << "YES";
		return 0;
	}
	int count;
	bool** s = new bool*[l];
	for (int i = 0; i < l; i++)
	{
		s[i] = new bool[r];
	}
	for (int i = 0; i < r; i++)
	{
		if (i == 0)
		{
			if ((a[0] == '?') || (a[0] == '*'))
			{
				s[0][i] = 1;
			}
			else
			{
				if (a[0] == b[0])
				{
					s[0][i] = 1;
				}
				else
				{
					s[0][i] = 0;
				}
			}
		}
		else
		{
			if (a[0] == '*')
			{
				s[0][i] = 1;
			}
			else
			{
				s[0][i] = 0;
			}
		}
	}
	for (int i = 0; i < l; i++)
	{
		if (i == 0)
		{
			if ((a[0] == '?') || (a[0] == '*'))
			{
				s[i][0] = 1;
			}
			else
			{
				if (a[0] == b[0])
				{
					s[i][0] = 1;
				}
				else
				{
					s[i][0] = 0;
				}
			}
		}
		else
		{
			count = 0;
			for (int j = 0; j <= i; j++)
			{
				if (a[j] != '*')
				{
					count++;
					if (a[j] != '?')
					{
						if (a[j] != b[0])
						{
							count = 2;
							s[i][0] = 0;
						}
					}
				}
			}
			if (count > 1)
			{
				s[i][0] = 0;
			}
			else
			{
				s[i][0] = 1;
			}
		}
	}
	int sum;
	for (int i = 1; i < l; i++)
	{
		sum = s[i - 1][0];
		for (int j = 1; j < r; j++)
		{
			if ((a[i] != '*') && (a[i] != '?'))
			{
				if (a[i] == b[j])
				{
					s[i][j] = s[i - 1][j - 1];
					sum += s[i - 1][j];
				}
				else
				{
					s[i][j] = 0;
					sum += s[i - 1][j];
				}
			}
			else
			{
				if (a[i] == '?')
				{
					s[i][j] = s[i - 1][j - 1];
					sum += s[i - 1][j];
				}
				else
				{
					s[i][j] = 0;
					sum += s[i - 1][j];
					if (sum >= 1)
					{
						s[i][j]= 1;
					}
				}
			}
		}
	}
	if(s[l - 1][r - 1] == 1)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}