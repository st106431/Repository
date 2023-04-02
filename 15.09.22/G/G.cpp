#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

int main()
{
	string s;
	int k;
	vector <char> res;
	cin >> s;
	cin >> k;
	for (auto elem : s)
	{
		if (count(s.begin(), s.end(), elem) >= k && count(res.begin(), res.end(), elem) == 0)
		{
			res.push_back(elem);
		}
	}
	sort(res.begin(), res.end());
	copy(res.begin(), res.end(), ostream_iterator <char>(cout, " "));
}