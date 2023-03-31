#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	int* s = new int[n + 1];
	int* a = new int[n + 1];
	int* b = new int[n + 1];
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
	}
	a[1] = s[1];
	b[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		a[i] = b[i - 1] + s[i];
		b[i] = max(a[i - 1], b[i - 1]);
	}
	cout << max(a[n], b[n]);
}