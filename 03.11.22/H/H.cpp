#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	char* s = new char[max(n + 1, (long long)10)];
	long long* a = new long long[max(n + 1, (long long)10)];
	long long* b = new long long[max(n + 1, (long long)10)];
	vector <long long>* x = new vector<long long>[max(n + 1, (long long)10)];
 	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
	}
	a[1] = 0;
	b[1] = 0;
	a[2] = n + 1;
	b[2] = -1;
	x[2].push_back(-1);
	if (s[3] != 'w')
	{
		a[3] = 1;
		if (s[3] == '"')
		{
			b[3] = 1;
		}
		else
		{
			b[3] = 0;
		}
	}
	else
	{
		a[3] = n + 1;
		b[3] = -1;
	}
	x[3].push_back(1);
	x[3].push_back(3);
	for (int i = 4; i <= 6; i++)
	{
		if(s[i] != 'w')
		{
			a[i] = min(a[i - 3], a[i - 2]);
			if (a[i] == n + 1)
			{
				b[i] = -1;
				x[i].push_back(-1);
			}
			else
			{
				if (a[i - 3] != a[i - 2])
				{
					if (a[i] == a[i - 2])
					{
						x[i] = x[i - 2];
						if (s[i] == '"')
						{
							b[i] = b[i - 2] + 1;
						}
						else
						{
							b[i] = b[i - 2];
						}
					}
					else
					{
						x[i] = x[i - 3];
						if (s[i] == '"')
						{
							b[i] = b[i - 3] + 1;
						}
						else
						{
							b[i] = b[i - 3];
						}
					}
				}
				else
				{
					if (b[i - 2] >= b[i - 3])
					{
						x[i] = x[i - 2];
						if (s[i] == '"')
						{
							b[i] = b[i - 2] + 1;
						}
						else
						{
							b[i] = b[i - 2];
						}
					}
					else
					{
						x[i] = x[i - 3];
						if (s[i] == '"')
						{
							b[i] = b[i - 3] + 1;
						}
						else
						{
							b[i] = b[i - 3];
						}
					}
				}
				x[i].push_back(i);
				if (a[i] != n + 1)
				{
					a[i]++;
				}
			}
		}
		else
		{
			a[i] = n + 1;
			b[i] = -1;
			x[i].push_back(-1);
		}
	}
	for (int i = 7; i <= n; i++)
	{
		int k = 0;
		bool mas[3]{ 0 };
		if (s[i] != 'w')
		{
			a[i] = min(a[i - 3], a[i - 2], a[i - 6]);
			if (a[i] == n + 1)
			{
				b[i] = -1;
				x[i].push_back(-1);
			}
			else
			{
				if (a[i - 2] == a[i - 3])
				{
					k++;
					mas[0] = 1;
				}
				if (a[i - 2] == a[i - 6])
				{
					k++;
					mas[1] = 1;
				}
				if (a[i - 3] == a[i - 6])
				{
					k++;
					mas[2] = 1;
				}
				if (k == 0)
				{
					if (a[i] == a[i - 2])
					{
						b[i] = b[i - 2];
						x[i] = x[i - 2];
					}
					if (a[i] == a[i - 3])
					{
						b[i] = b[i - 3];
						x[i] = x[i - 3];
					}
					if (a[i] == a[i - 6])
					{
						b[i] = b[i - 6];
						x[i] = x[i - 6];
					}
					if (s[i] == '"')
					{
						b[i]++;
					}
					a[i]++;
					x[i].push_back(i);
				}
				else
				{
					if (k == 1)
					{

					}
					else
					{

					}
				}
				if (a[i - 3] != a[i - 2])
				{
					if (a[i] == a[i - 2])
					{
						x[i] = x[i - 2];
						if (s[i] == '"')
						{
							b[i] = b[i - 2] + 1;
						}
						else
						{
							b[i] = b[i - 2];
						}
					}
					else
					{
						x[i] = x[i - 3];
						if (s[i] == '"')
						{
							b[i] = b[i - 3] + 1;
						}
						else
						{
							b[i] = b[i - 3];
						}
					}
				}
				else
				{
					if (b[i - 2] >= b[i - 3])
					{
						x[i] = x[i - 2];
						if (s[i] == '"')
						{
							b[i] = b[i - 2] + 1;
						}
						else
						{
							b[i] = b[i - 2];
						}
					}
					else
					{
						x[i] = x[i - 3];
						if (s[i] == '"')
						{
							b[i] = b[i - 3] + 1;
						}
						else
						{
							b[i] = b[i - 3];
						}
					}
				}
				//x[i].push_back(i);
			}
		}
		else
		{
			a[i] = n + 1;
			b[i] = -1;
			x[i].push_back(-1);
		}
	}
	if (a[n] != n + 1)
	{
		cout << a[n] << " " << b[n] << endl;
	}
	else
	{
		cout << -1;
	}
}