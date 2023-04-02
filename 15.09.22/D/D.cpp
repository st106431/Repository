#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <vector>
using namespace std;

int main()
{
	int l, r, d, h, t;
	int s = 0;
	cin >> l >> r >> d;
	r = r - r % d;
	if (l % d != 0)
	{
		l = l + d - l % d;
	}
	if (r < l)
	{
		return 0;
	}
	h = r / d - l / d;
	vector <int> v (h + 1);
	iota(v.begin(), v.end(), l / d);
	s = l;
	generate_n(ostream_iterator <int>(cout, " "), h + 1, [&] () {t = s;  s += d; return t; });
}