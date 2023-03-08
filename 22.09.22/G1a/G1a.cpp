#include <iostream>
using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;
	if ((m * n - 1) % 2 == 1)
	{
		cout << "First";
	}
	else
	{
		cout << "Second";
	}
}