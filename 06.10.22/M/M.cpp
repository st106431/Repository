#include <iostream>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	if (n == 1)
	{
		cout << "NO";
		return 0;
	}
	if (n == 2)
	{
		cout << "YES";
		return 0;
	}
	if ((n % 2) == 0)
	{
		cout << "NO";
		return 0;
	}
	if (((n % 3) == 0) && (n != 3))
	{
		cout << "NO";
		return 0;
	}
	long long c = (long long)sqrt(n);
	long long* s = new long long[c + 1] {(long long)1};
	for (int h = 0; h < c + 1; h++)
	{
		s[h] = 1;
	}
	s[0] = 0;
	s[1] = 1;
	long long j;
	for (long long i = 2; i <= c; i++)
	{
		if (s[i] != 0)
		{
			if ((n % i) == 0)
			{
				cout << "NO";
				return 0;
			}
			else
			{
				j = i;
				while (j <= c)
				{
					s[j] = 0;
					j += i;
				}
			}
		}
	}
	cout << "YES";
}
