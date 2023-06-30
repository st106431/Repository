#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

int main()
{
	int n;
	char s[1000];
	cin >> n;
	_itoa_s(n, s, 10);
	n = atoi(s);
	//_itoa_s(n, s, 7);
	//n = atoi(s);
	cout << s;
}
