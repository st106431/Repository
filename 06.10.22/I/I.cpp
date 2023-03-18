#include <iostream>
#include <map>
using namespace std;

int discrete_log(int a, int b, int p) 
{
	int phi_p = p - 1;
	int lim = (int)(sqrt(phi_p)) + 1;
	map <int, int> power;
	int a_lim = 1;
	for (int i = 0; i < lim; i++) 
	{
		power[a_lim] = i;
		a_lim = (a_lim * 1LL * a) % p;
	}
	for (int i = 0; i < lim; i++) 
	{
		if (power.count(b))
		{
			return (power[b] - i * lim + phi_p) % phi_p;
		}
		b = (b * 1LL * a_lim) % p;
	}
	return -1;
}


int main()
{
	int a, b, n;
	cin >> a >> b >> n;
	cout << discrete_log(a, b, n);
}
