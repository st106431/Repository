#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if (n % 8 == 0 || n % 8 == 1)
	{
		cout << "Second";
	}
	else
	{
		cout << "First";
	}
}