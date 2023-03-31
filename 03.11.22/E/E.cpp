#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	long long * s = new long long[max(n + 1, 7)];
	s[0] = 1;
	s[1] = 0;
	s[2] = 1;
	s[3] = 1;
	s[4] = 1;
	s[5] = 2;
	for (int i = 6; i <= n; i++)
	{
		s[i] = s[i - 2] + s[i - 3];
	}
	cout << s[n];
}