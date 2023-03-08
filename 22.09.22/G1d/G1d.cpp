#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if (n % 6 == 1 || n % 6 == 3 || n % 6 == 5)
	{
		cout << "First";
	}
	else
	{
		cout << "Second";
	}
}