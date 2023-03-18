#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int a, b;
	int count = 0;
	cin >> a >> b;
	vector<int> s(b + 1);
	if (b == 3)
	{
		if (a == 3)
		{
			cout << 1;
			return 0;
		}
		if (a <= 2)
		{
			cout << 2;
			return 0;
		}
	}
	for (int i = 2; i * i <= b; i++)
	{
		if (!s[i - 1])
		{
			for (int j = i * i; j <= b; j += i)
			{
				s[j - 1] = 1;
			}
		}
	}
	for (int i = a; i <= b; i++)
	{
		if(s[i - 1])
		{
			count++;
		}
	}
	if (a != 1)
	{
		cout << b - a + 1 - count;
	}
	else
	{
		cout << b - a - count;
	}
}
