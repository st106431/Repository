#include <iostream>
using namespace std;

int main()
{
	int n, k, s, q, r, f;
	cin >> n;
	s = n;
	if (n == 1)
	{
		cout << -1;
		return 0;
	}
	if (n % 2 == 1)
	{
		cout << 3 << " " << (n - 1) / 2 << " " << (n + 1) / 2 << " " << (n + 3) / 2 << endl;
		s -= 3;
	}
	else
	{
		cout << 2 << " " << n / 2 << " " << n / 2 + 1 << endl;
		s -= 2;
	}
	while (s > 0)
	{
		cin >> k;
		if (k == -1)
		{
			return 0;
		}
		if (k == 3)
		{
			cin >> q >> r >> f;
			cout << k << " " << n + 1 - f << " " << n + 1 - r << " " << n + 1 - q << endl;
		}
		else
		{
			cin >> q >> r;
			cout << k << " " << n + 1 - r << " " << n + 1 - q << endl;
		}
		s -= 2 * k;
	}
}
