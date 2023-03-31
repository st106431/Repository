#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	char* s = new char[max(n + 1, 10)];
	long long * res = new long long[max(n + 1, 10)];
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
	}
	res[1] = 0;
	switch (s[2])
	{
	case 'w':
		res[2] = -1;
		break;
	case '"':
		res[2] = 1;
		break;
	case '.':
		res[2] = 0;
		break;
	}
	if (s[3] == 'w')
	{
		res[3] = -1;
	}
	else
	{
		if (res[2] != -1)
		{
			if (s[3] == '"')
			{
				res[3] = res[2] + 1;
			}
			else
			{
				res[3] = res[2];
			}
		}
		else
		{
			res[3] = -1;
		}
	}
	switch (s[4])
	{
	case 'w':
		res[4] = -1;
		break;
	case '"':
		if (res[3] != -1)
		{
			res[4] = res[3] + 1;
		}
		else
		{
			res[4] = 1;
		}
		break;
	case '.':
		if (res[3] != -1)
		{
			res[4] = res[3];
		}
		else
		{
			res[4] = 0;
		}
		break;
	}
	switch (s[5])
	{
	case 'w':
		res[5] = -1;
		break;
	case '"':
		if (s[4] != 'w')
		{
			res[5] = max(res[4] + 1, res[2] + 1);
		}
		else
		{
			if (res[2] != -1)
			{
				res[5] = res[2] + 1;
			}
			else
			{
				res[5] = -1;
			}
		}
		break;
	case '.':
		if (s[4] != 'w')
		{
			res[5] = max(res[4], res[2]);
		}
		else
		{
			if (res[2] != -1)
			{
				res[5] = res[2];
			}
			else
			{
				res[5] = -1;
			}
		}
		break;
	}
	for (int i = 6; i <= n; i++)
	{
		if (s[i] == 'w')
		{
			res[i] = -1;
		}
		else
		{
			res[i] = max(res[i - 5], max(res[i - 3], res[i - 1]));
			if (s[i] == '"' && res[i] != -1)
			{
				res[i]++;
			}
		}
	}
	cout << res[n];
}