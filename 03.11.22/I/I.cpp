#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	long long* s = new long long[10];
	if (n == 1)
	{
		cout << 9;
		return 0;
	}
	s[0] = 0;
	for (int i = 1; i <= 9; i++)
	{
		s[i] = 1;
	}
	for (int i = 0; i <= n - 2; i++)
	{
		long long* curr = new long long[10] {0};
		for (int j = 1; j <= 8; j++)
		{
			curr[j] = s[j] + s[j - 1] + s[j + 1];
		}
		curr[0] = s[0] + s[1];
		curr[9] = s[9] + s[8];
		for (int j = 0; j <= 9; j++)
		{
			s[j] = curr[j];
		}
	}
	long long count = 0;
	for (int i = 0; i <= 9; i++)
	{
		count += s[i];
	}
	cout << count;
}