#include <iostream>
using namespace std;

pair <int, int> lin_gcd(int a, int b)
{
	if (a % b == 0)
	{
		if (b == 1 || b == -1)
		{
			return make_pair(0, b);
		}
		else
		{
			return make_pair(0, 0);
		}
	}
	pair <int, int> p;
	pair <int, int> pa;
	p = lin_gcd(b, a % b);
	pa.first = p.second;
	pa.second = p.first - (p.second * (a / b));
	return pa;
}

int main()
{
	int n, m;
	cin >> n >> m;
	cout << lin_gcd(n, m).first << " " << lin_gcd(n, m).second;
}