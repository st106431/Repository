#include <iostream>
using namespace std;

int main()
{
	int n, k;
	cin >> n;
	if (n % 3 == 0)
	{
		cout << -1;
		return 0;
	}
	else
	{
		cout << n % 3 << endl;
		n -= n % 3;
	}
	while (n > 0)
	{
		cin >> k;
		cout << 3 - k << endl;
		n -= 3;
	}
}