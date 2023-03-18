#include <iostream>
#include <string>
#include <map>
using namespace std;
int pr;

string perv(int p, int x)
{
	int k = 1;
	int pr = x % p;
	while (pr != 1)
	{
		pr = (pr * x) % p;
		k++;
	}
	if (k == p - 1)
	{
		return "YES";
	}
	else
	{
		return "NO";
	}
}

string log(long long a, long long p) 
{
	long long phi_p = p - 1;
	long long v = 1;
	long long lim = (int)(sqrt(phi_p)) + 1;
	map <long long, int> power;
	long long a_lim = 1;
	for (int i = 0; i <= lim; i++) 
	{
		power[a_lim] = i;
		a_lim = (a_lim * 1LL * a) % p;
	}
	for (int i = 0; i <= lim; i++) 
	{
		if (power.count(v))
		{
			if (((power[v] - ((long long)i * lim)) % phi_p) == 0)
			{
				return "YES";
			}
			else
			{
				return "NO";
			}
		}
		v = (v * 1LL * a_lim) % p;
	}
	return "NO";
}


int main()
{
	int n, p;
	cin >> n >> p;
	int* mas = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> mas[i];
	}
	for (int i = 0; i < n; i++)
	{
		cout << log(mas[i], p) << endl;
	}
}
