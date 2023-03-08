#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;
multiset<pair<int, int>> s;
multiset<pair<int, int>> ::iterator it = s.begin();

pair <int, int> piece(multiset<pair<int, int>> s)
{
	it = s.begin();
	while ((*it) == make_pair(1, 1))
	{
		it++;
	}
	pair <int, int> p = *it;
	return p;
}

int main()
{
	int m, n;
	int k[6];
	//multiset<pair<int, int>> s;
	cin >> m >> n;
	if (m <= n)
	{
		s.insert(make_pair(m, n));
	}
	else
	{
		s.insert(make_pair(n, m));
	}
	int mx, mn;
	if ((m * n - 1) % 2 == 1)
	{
		for (int i = 1; i <= m * n - 1; i++)
		{
			mx = max(piece(s).first, piece(s).second);
			mn = min(piece(s).first, piece(s).second);
			if (i % 2 == 1)
			{
				cout << piece(s).first << " " << piece(s).second << " " << 1 << " " << mn << " " << mx - 1 << " " << mn << endl;
				fflush(stdout);
				s.erase(make_pair(piece(s).first, piece(s).second));
				s.insert(make_pair(1, mn));
				if (mx - 1 <= mn)
				{
					s.insert(make_pair(mx - 1, mn));
				}
				else
				{
					s.insert(make_pair(mn, mx - 1));
				}
			}
			else
			{
				cin >> k[0];
				if (k[0] != -1)
				{
					cin >> k[1] >> k[2] >> k[3] >> k[4] >> k[5];
					if (k[0] <= k[1])
					{
						s.erase(make_pair(k[0], k[1]));
					}
					else
					{
						s.erase(make_pair(k[1], k[0]));
					}
					if (k[2] <= k[3])
					{
						s.insert(make_pair(k[2], k[3]));
					}
					else
					{
						s.insert(make_pair(k[3], k[2]));
					}
					if (k[4] <= k[5])
					{
						s.insert(make_pair(k[4], k[5]));
					}
					else
					{
						s.insert(make_pair(k[5], k[4]));
					}
				}
			}
		}
	}
	else
	{
		cout << -1 << endl;
	}
}
