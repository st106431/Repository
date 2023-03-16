#include <iostream>
using namespace std;

int gcd(long long a, long long b)
{
	if (a == 0)
	{
		return b;
	}
	return gcd(b % a, a);
}

int lcm(long long a, long long b) 
{
	if ((a / gcd(a, b)) * b <= 1000000000)
	{
		return (a / gcd(a, b)) * b;
	}
	else
	{
		return 1000000001;
	}
}

int main()
{
	long long k, l, m, n, s;
	cin >> k >> l >> m >> n;
	s = 0;
	s = n / k + n / l + n / m - n / lcm(k, l) - n / lcm(l, m) - n / lcm(k, m) + n / lcm(lcm(k, l), m);
	cout << s;
}
