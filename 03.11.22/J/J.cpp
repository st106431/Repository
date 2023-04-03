#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	long long** s = new long long* [max(n + 2, 5)];
	for (int i = 0; i < max(n + 2, 5); i++)
	{
		s[i] = new long long[3];
	}
	long long* res = new long long[max(n + 2, 5)];
	for (int i = 0; i < 3; i++)
	{
		s[0][i] = 0;
	}
	for (int i = 0; i < 3; i++)
	{
		s[1][i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> s[i][0] >> s[i][1] >> s[i][2];
	}
	res[0] = 0;
	res[1] = s[0][0];
	res[2] = min(s[0][0] + s[1][0], s[0][1]);
	res[3] = min(min(s[0][2], s[0][0] + s[1][1]), s[0][0] + s[1][0] + s[2][0]);
	res[3] = min(res[3], s[0][1] + s[1][1]);
	if (n == 1)
	{
		cout << s[0][0];
		return 0;
	}
	if (n <= 3)
	{
		cout << res[n];
		return 0;
	}
	for (int i = 4; i <= n; i++)
	{
		res[i] = min(min(res[i - 1] + s[i - 1][0], res[i - 2] + s[i - 2][1]), res[i - 2] + s[i - 2][0] + s[i - 1][0]);
		res[i] = min(res[i], res[i - 3] + s[i - 3][2]);
		res[i] = min(min(res[i], res[i - 3] + s[i - 3][0] + s[i - 2][1]), res[i - 3] + s[i - 3][0] + s[i - 2][0] + s[i - 1][0]);
		res[i] = min(res[i], res[i - 3] + s[i - 3][1] + s[i - 1][0]);
		res[i] = min(min(res[i], res[i - 2] + s[i - 3][2]), res[i - 2] + s[i - 3][1] + s[i - 1][0]);
		res[i] = min(res[i], res[i - 2] + s[i - 3][1] + s[i - 2][1]);
		res[i] = min(min(res[i], res[i - 1] + s[i - 3][2]), res[i - 1] + s[i - 2][1]);
	}
	cout << res[n];
}