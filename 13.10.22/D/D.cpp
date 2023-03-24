#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int n;
	cin >> n;
	long long* s = new long long[n];
	long long k = 0;
	double sum = 0.0;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		k += s[i];
		sum += 1.0 / s[i];
	}
	cout << fixed << setprecision(15) << k + sum;
}