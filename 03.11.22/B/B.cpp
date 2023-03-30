#include <iostream>
#include <algorithm>
using namespace std;

int f(int* s, int k)
{
	if (k == 0)
	{
		return 0;
	}
	if (k == 1)
	{
		return s[1];
	}
	return s[k] + max(f(s, k - 1), f(s, k - 2));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	int* s = new int[n + 1];
	int* res = new int[n + 1];
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
	}
	res[0] = 0;
	res[1] = s[1];
	for (int i = 2; i <= n; i++)
	{
		res[i] = s[i] + max(res[i - 1], res[i - 2]);
	}
	cout << res[n];
}