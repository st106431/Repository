#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <numeric>
using namespace std;

vector<int> a;

bool in(int q)
{
	if (count(a.begin(), a.end(), q) == 0)
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
	int n;
	cin >> n;
	vector <int> s(n);
	iota(s.begin(), s.end(), -1000000);
	copy_n(istream_iterator <int>(cin), n, s.begin());
	a.resize(n);
	iota(a.begin(), a.end(), -1000000);
	if (*max_element(s.begin(), s.end()) < 0)
	{
		cout << 0;
		return 0;
	}
	vector<int>::iterator it = copy_if(s.begin(), s.end(), a.begin(), [](int k) {return k >= 0; });
	a.resize(distance(a.begin(), it));
	if (a.size() == 0)
	{
		cout << 0;
		return 0;
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	sort(a.begin(), a.end());
	vector <int> w((*max_element(a.begin(), a.end())) + 10);
	cout << w.size() << endl << endl;
	iota(w.begin(), w.end(), 0);
	vector<int>::iterator it_1;
	it_1 = find_if(w.begin(), w.end(), in);
	cout << *it_1;
}