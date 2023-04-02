#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

int main()
{
	int n, x;
	cin >> n;
	vector <int> s(n);
	copy_n(istream_iterator <int>(cin), n, s.begin());
	x = s[0];
	sort(s.begin(), s.end());
	cout << find(s.begin(), s.end(), x) - s.begin() + 1;
}