#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

int k;
string s;

char zero()
{
	return '0';
}

bool in(char x)
{
	if (count(s.begin(), s.end(), x) >= k)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	vector <char> res(101);
	cin >> s;
	cin >> k;
	int l = 0;
	generate(res.begin(), res.end(), zero);
	copy_if(s.begin(), s.end(), res.begin(), in);
	l = 101 - count(res.begin(), res.end(), '0');
	res.resize(l);
	sort(res.begin(), res.end());
	vector<char>::iterator it;
	it = unique(res.begin(), res.end());
	res.resize(distance(res.begin(), it));
	copy(res.begin(), res.end(), ostream_iterator <char>(cout, " "));
}