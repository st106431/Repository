#include <iostream>
using namespace std;

bool prime(int n) 
{
	if (n < 2)
	{
		return false;
	}
	for (int d = 2; d * d <= n; d++)
	{
		 if (n % d == 0) 
		 {
			return false;
		 }
	}
	return true;
}

int main()
{
	long long n;
	long long k = 0;
	cin >> n;
	for (long long i = 1; i * i <= n; i++)
	{
		if (i * i == n)
		{
			k++;
		}
		else
		{
			if (n % i == 0)
			{
				k += 2;
			}
		}
	}
	cout << k;
}