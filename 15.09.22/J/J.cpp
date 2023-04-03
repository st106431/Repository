#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <int> s(n);
	copy_n(istream_iterator <int> (cin), n, s.begin());
	sort(s.begin(), s.begin() + n / 2);
	sort(s.begin() + n / 2, s.end());
	reverse(s.begin() + n / 2, s.end());
	copy(s.begin(), s.end(), ostream_iterator <int>(cout, " "));
}