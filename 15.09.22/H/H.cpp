#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

int main()
{
	int n, number;
	cin >> n;
	vector <int> s(n);
	int k = -1;
	copy_n(istream_iterator <int>(cin), n, s.begin());
	for (auto elem : s)
	{
		if (count(s.begin(), s.end(), elem) > k)
		{
			k = count(s.begin(), s.end(), elem);
			number = elem;
		}
	}
	cout << number;
}