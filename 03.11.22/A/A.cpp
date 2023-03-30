#include <iostream>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	long long* s = new long long[n + 1];
	s[0] = 0;
	s[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		s[i] = s[i - 2] + s[i - 1];
	}
	cout << s[n];
}