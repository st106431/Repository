#include <iostream>
using namespace std;

int main()
{
	long long a, b;
	cin >> a >> b;
	if (b == 0)
	{
		cout << "Na nol' delit' nel'zya!!!";
		return 0;
	}
	if (a % b == 0)
	{
		cout << a / b;
		return 0;
	}
	if ((a > 0) && (b > 0))
	{
		cout << a / b;
		return 0;
	}
	if ((a > 0) && (b < 0))
	{
		cout << a / b - 1;
		return 0;
	}
	if ((a < 0) && (b > 0))
	{
		cout << a / b - 1;
		return 0;
	}
	if ((a < 0) && (b < 0))
	{
		cout << a / b + 1;
		return 0;
	}
}
