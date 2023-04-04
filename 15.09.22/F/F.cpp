#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

string t;

bool contain(char x)
{
	if (count(t.begin(), t.end(), x) == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

char zero()
{
	return '0';
}

int main()
{
	string s;
	string f;
	int k = 0;
	f.resize(101);
	generate(f.begin(), f.end(), zero);
	vector <char> res;
	cin >> s;
	cin >> t;
	remove_copy_if(s.begin(), s.end(), f.begin(), contain);
	k = 101 - count(f.begin(), f.end(), '0');
	f.resize(k);
	copy(f.begin(), f.end(), ostream_iterator <char> (cout));
}