#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, t;
	cin >> n;
	int** s = new int*[300];
	int** res = new int*[300];
	for (int i = 0; i < 300; i++)
	{
		s[i] = new int[300];
		res[i] = new int[300] {0};
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> s[i][j];
		}
	}
	if (n == 1)
	{
		cout << s[0][0];
		return 0;
	}
	res[0][0] = s[0][0];
	res[1][1] = s[0][0] + s[1][1];
	res[1][0] = s[0][0] + s[1][0];
	if (n == 2)
	{
		t = max(res[1][1], res[1][0]);
		cout << t;
		return 0;
	}
	for (int i = 2; i < n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			t = max(res[i - 1][j - 1], res[i - 1][j]);
			res[i][j] = t + s[i][j];
		}
		res[i][0] = res[i - 1][0] + s[i][0];
		res[i][i] = res[i - 1][i - 1] + s[i][i];
	}
	sort(res[n - 1], res[n - 1] + n);
	cout << res[n - 1][n - 1];
}