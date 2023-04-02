#include <iostream>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <vector>
using namespace std;

int main()
{
	long long n, pr, a;
	long double l;
	cin >> n;
	if (n == 1)
	{
		cout << 1;
		return 0;
	}
	pr = 1;
	if (n == 10)
	{
		l = 10;
	}
	else
	{
		l = log(1000000000) / log(n);
		if (abs(1000000000 - (n ^ (int)l) < pow(10, -10)))
		{
			l = (int)l + 1;
		}
		else
		{
			l = (int)l + 1;
		}
	}
	vector <int> v((int)l);
	generate(v.begin(), v.end(), [&]() {a = pr; pr *= n;  return a; });
	copy(v.begin(), v.end(), ostream_iterator <int>(cout, " "));
}
