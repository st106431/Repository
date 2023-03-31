#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int* s = new int[n + 1];
	s[1] = 2;
	s[2] = 4;
	s[3] = 7;
	for (int i = 4; i <= n; i++)
	{
		s[i] = (s[i - 3] + s[i - 2] + s[i - 1]) % 12345;
	}
	cout << s[n];
}