#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
	int n, t;
	cin >> n;
	int* mas = new int[n];
	multiset <int> s;
	for (int i = 0; i < n; i++)
	{
		cin >> mas[i];
		s.insert(mas[i]);
	}
	for (int i = 0; i < n; i++)
	{
		if (s.count(mas[i]) == 1 || s.count(mas[i]) == 5)
		{
			cout << mas[i];
			return 0;
		}
	}
}
