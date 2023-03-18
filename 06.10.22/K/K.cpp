#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <int> s(n);
	for (int i = 2; i * i <= n; i++)
	{
		if (!s[i - 1])
		{
			for (int j = i * i; j <= n; j += i)
			{
				s[j - 1] = 1;
			}
		}
	}
	if (s[n - 1])
	{
		cout << "NO";
	}
	else
	{
		cout << "YES";
	}
}
