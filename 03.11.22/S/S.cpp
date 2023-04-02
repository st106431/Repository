#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a, b;
	getline(cin, a);
	getline(cin, b);
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
	int** s = new int*[l];
	for (int i = 0; i < l; i++)
	{
		s[i] = new int[r];
	}
	for (int i = 0; i < r; i++)
	{
		if (i == 0)
		{
			if (a[0] == '?' || a[0] == '*')
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
			if (a[0] == '?' || a[0] == '*')
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
			int count = 0;
			for (int j = 0; j < l; j++)
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
							break;
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
	for (int i = 1; i < l; i++)
	{
		for (int j = 1; j < r; j++)
		{
			if ((a[i] != '*') && (a[i] != '?'))
			{
				if (a[i] == b[j])
				{
					s[i][j] = s[i - 1][j - 1];
				}
				else
				{
					s[i][j] = 0;
				}
			}
			else
			{
				if (a[i] == '?')
				{
					s[i][j] = s[i - 1][j - 1];
				}
				else
				{
					s[i][j] = 0;
					for (int k = 0; k <= j; k++)
					{
						if (s[i - 1][k] == 1)
						{
							s[i][j] = 1;
						}
					}
					if (s[i][j] != 1)
					{
						int y = 0;
						for (int q = 0; q <= i - 1; q++)
						{
							if (a[q] == '*')
							{
								y++;
							}
						}
						if (y == i)
						{
							s[i][j] = 1;
						}
						else
						{
							s[i][j] = 0;
						}
					}
				}
			}
		}
	}
	if (s[l - 1][r - 1] == 1)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}