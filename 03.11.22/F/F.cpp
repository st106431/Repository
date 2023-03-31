#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int l = n + 1;
	int* s = new int[l];
	long long* sum = new long long[l];
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
	}
	s[0] = -1;
	if (n == 2)
	{
		cout << abs(s[2] - s[1]);
		return 0;
	}
	if (n == 3)
	{
		cout << abs(s[3] - s[1]);
		return 0;
	}
	sort(s, s + l);
	sum[1] = 0;
	sum[2] = (long long)s[2] - (long long)s[1];
	sum[3] = (long long)s[3] - (long long)s[1];
	for (int i = 4; i <= n; i++)
	{
		sum[i] = min(sum[i - 2], sum[i - 1]) + (long long)(s[i] - s[i - 1]);
	}
	cout << sum[n];
}