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

}