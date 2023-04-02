#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

int main()
{
	string s;
	cin >> s;
	char letter;
	int k = -1;
	for (auto elem : s)
	{
		if (count(s.begin(), s.end(), elem) > k)
		{
			letter = elem;
			k = count(s.begin(), s.end(), elem);
		}
	}
	cout << letter;
}