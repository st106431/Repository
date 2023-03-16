#include <iostream>
using namespace std;

int O(int* s, int* t, int l, int r, int k)
{
	int i = l;
	int ka = i;
	int j = k;
	int count = 0;
	while ((i < k) && (j <= r))
	{
		if (s[i] <= s[j])
		{
			t[ka++] = s[i++];
		}
		else
		{
			t[ka++] = s[j++];
			count += k - i;
		}
	}
	while (i < k)
	{
		t[ka++] = s[i++];
	}
	while (j <= r)
	{
		t[ka++] = s[j++];
	}
	for (int i = l; i <= r; i++)
	{
		s[i] = t[i];
	}
	return count;
}

int merge_s(int* s, int* t, int l, int r)
{
	int k = (l + r) / 2;
	int count = 0;
	if (r > l)
	{
		count += merge_s(s, t, l, k);
		count += merge_s(s, t, k + 1, r);
		count += O(s, t, l, r, k + 1);
	}
	return count;
}

int main()
{
	int n;
	cin >> n;
	int* s = new int[n];
	int* t = new int[n] {0};
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	cout << merge_s(s, t, 0, n - 1);
}
