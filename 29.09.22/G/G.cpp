#include <iostream>
#include <string>
#include <random>
using namespace std;
int f;
mt19937 rng(1234356);

int gen(int l, int r)
{
	//mt19937 rng(1234356);
	uniform_int_distribution <int> random(l, r);
	return random(rng);
}

void shift(int* a, int n)
{
	int temp = a[0];
	for (int i = 0; i < n - 1; i++)
	{
		a[i] = a[i + 1];
	}
	a[n - 1] = temp;
}

int sokr(int x, int y)
{
	f = max(x, y) % min(x, y);
	int q;
	if (f == 0)
	{
		q = min(x, y);
		return q;
	}
	else
	{
		sokr(min(x,y), f);
	}
}

string output(int x, int y)
{
	string ou;
	int nod = sokr(x, y);
	ou = to_string(x / nod) + "/" + to_string(y / nod);
	return ou;
}

int partition(double* a, int l, int r, double x)
{
	int i = l;
	int j = r - 1;
	while (i <= j)
	{
		while (a[i] < x)
		{
			i += 1;
		}
		while (x < a[j])
		{
			j -= 1;
	    }
		if (i >= j)
		{
			break;
		}
		swap(a[i], a[j]);
		i++;
		j--;
	}
	return i;
}

int quick_select(int* a, int k, int l, int r)
{
	while ((r - l) > 1)
	{
		int x = a[gen(l, r)];
		int i = l;
		int j = r - 1;
		while (i <= j)
		{
			while (a[i] < x) { i += 1; }
			while (x < a[j]) { j -= 1; }
			if (i >= j)
			{
				break;
			}
			swap(a[i], a[j]);
			i += 1;
			j -= 1;
		}
		if (k < i)
		{
			r = i;
		}
		else
		{
			l = i;

		}
	}
	return l;
}

string res(int* a, int* b, double* t, int n, int k)
{
	for (int i = 0; i < n; i++)
	{
		t[i] = static_cast<double>(a[i]) / b[i];
	}
	//cout << quick_select(t, k, 0, n - 1) << " ";
	return output(a[quick_select(t, k, 0, n - 1)], b[quick_select(t, k, 0, n - 1)]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	int* s_1 = new int[n];
	int* s_2 = new int[n];
	double* t = new double[n];
	for (int i = 0; i < n; i++)
	{
		cin >> s_1[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> s_2[i];
	}
	for (int i = 0; i < n; i++)
	{
		shift(s_2, n);
		cout << res(s_1, s_2, t, n, k) << " ";
	}
}
