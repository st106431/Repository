#include <iostream>
using namespace std;

int main()
{
	int n, k, t;
	cin >> n;
	if (n % 8 == 0 || n % 8 == 1)
	{
		cout << -1;
		return 0;
	}
	else
	{
		t = (n % 8) - ((n % 8) % 2);
		cout << t << endl;
		n -= t;
	}
	while (n > 0)
	{
		cin >> k;
		cout << 8 - k << endl;
		n -= 8;
	}
}
