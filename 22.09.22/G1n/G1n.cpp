#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int m, n, k, t;
	cin >> m >> n;
	if (m == n)
	{
		cout << -1;
		return 0;
	}
	else
	{
		if (m > n)
		{
			cout << 1 << " " << m - n << endl;
			m = n;
		}
		else
		{
			cout << 2 << " " << n - m << endl;
			n = m;
		}
	}
	while (m + n > 0)
	{
		cin >> k >> t;
		cout << 3 - k << " " << t << endl;
		m -= t;
		n -= t;
	}
}
