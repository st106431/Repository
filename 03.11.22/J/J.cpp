#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	int** s = new int* [max(n, 4)] {0};
	for (int i = 0; i < max(n, 4); i++)
	{
		s[i] = new int[3];
	}
	int* res = new int[max(n, 4)];
	for (int i = 0; i < 3; i++)
	{
		s[1][i] = 0;
	}
	for (int i = 0; i < 3; i++)
	{
		s[2][i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> s[i][0] >> s[i][1] >> s[i][2];
	}
	res[0] = 0;
	res[1] = s[0][0];
	res[2] = min(s[0][0] + s[1][0], s[0][1]);
	if (n <= 3)
	{
		cout << res[n - 1];
		return 0;
	}
	for (int i = 3; i <= n - 1; i++)
	{
		res[i] = min(min(res[i - 1] + s[i - 1][0], res[i - 2] + s[i - 2][1]), res[i - 2] + s[i - 2][0] + s[i - 1][0]);
		res[i] = min(res[i], res[i - 3] + s[i - 3][2]);
		res[i] = min(min(res[i], res[i - 3] + s[i - 3][0] + s[i - 2][1]), res[i - 3] + s[i - 3][0] + s[i - 2][0] + s[i - 1][0]);
		res[i] = min(res[i], res[i - 3] + s[i - 3][1] + s[i - 1][0]);
	}
	cout << res[n - 1];
}