#include <iostream>
using namespace std;

int main()
{
	int n, l;
	cin >> n;
	l = n;
	int* s = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	while (l--)
	{
		int k = 0;
		for (int i = 0; i < l; i++)
		{
			if (s[i] > s[i + 1])
			{
				swap(s[i], s[i + 1]);
				k = 1;
			}
		}
		if (k == 0)
		{
			break;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << s[i] << " ";
	}
}