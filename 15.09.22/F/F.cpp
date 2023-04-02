#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

int main()
{
	string s, t;
	vector <char> res;
	cin >> s;
	cin >> t;
	for (auto elem : s)
	{
		if (count(t.begin(), t.end(), elem) == 0)
		{
			res.push_back(elem);
		}
	}
	copy(res.begin(), res.end(), ostream_iterator <char> (cout));
}