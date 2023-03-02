#include <iostream>
using namespace std;

int main()
{

	int a, b, d;
	cin >> a >> b >> d;
	if (a <= b)
	{
		if (d < b - a)
		{
			cout << a + d;
		}
		else
		{
			cout<< b;
		}
	}
	else
	{
		if (d < a - b)
		{
			cout << a - d;
		}
		else
		{
			cout << b;
		}
	}
}
