#include <iostream>
#include <algorithm>
using namespace std;

void insert(int* d, int w, int b, int length)
{
    for (int i = length; i > b; i--)
    {
        d[i] = d[i - 1];
    }
    d[b] = w;
}

void bin(int* d, int w, int q, int length)
{
    int l = 1;
    int r = q;
    int x;
    while (l <= r)
    {
        int number = 0;
        if (l == r)
        {
            insert(d, w, l + 1, length);
            break;
        }
        if (r - l == 1)
        {
            if (d[l - 1] <= w)
            {
                insert(d, w, l, length);
                break;
            }
            else
            {
                insert(d, w, r, length);
                break;
            }
        }
        x = d[(l + r) / 2];
        if (x == w)
        {
            insert(d, w, (l + r) / 2 + 1, length);
            break;
        }
        if (x < w)
        {
            l = (l + r) / 2 + 1;
        }
        else
        {
            r = (l + r) / 2 - 1;
        }
    }
}

int main()
{
	int n, b, p;
	cin >> n >> b >> p;
    int* s = new int[n];
	long long pr = b;
	for (int i = 1; i <= n; i++)
	{
		s[i - 1] = pr % p;
		pr = ((pr % p) * (b % p)) % p;
	}
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << endl;
    }
    sort(s, s + n);
	for (int i = 1; i < n; i++)
	{
		s[0] = (s[0] + s[n - i]) % p;
        cout << s[n - i] << endl;
        bin(s, s[0], n - i, n + 1 - i);
		cout << s[0] << " ";
	}
}
