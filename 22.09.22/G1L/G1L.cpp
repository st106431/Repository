#include <iostream>
using namespace std;

int main()
{
	int n, k;
	cin >> n;
	if (n % 6 == 1 || n % 6 == 3 || n % 6 == 5)
	{
		cout << n % 6 << endl;
		n -= n % 6;
	}
	else
	{
		cout << -1;
		return 0;
	}
	while (n > 0)
	{
		cin >> k;
		cout << 6 - k << endl;
		n -= 6;
	}
}