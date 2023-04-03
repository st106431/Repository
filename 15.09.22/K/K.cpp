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
	copy_n(istream_iterator <int>(cin), n, s.begin());
	for (auto elem : s)
	{
		if (count(s.begin(), s.end(), elem) == 1)
		{
			cout << elem;
			return 0;
		}
	}
}