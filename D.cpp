#include <iostream>
#include <random>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

int m = 1000000007;
int mas_x[13]{ 0 };
int mas_y[13]{ 0 };
int tab[13][13]{ 0 };
int buff[3]{ 0 };

int polynom(int h)
{
	return (h * h + 1000000006) % m;
}

long long interpolation(int mas_x[13], int mas_y[13], int number, int x)
{
	for (int i = 0; i < number; i++)
	{
		tab[i][0] = mas_y[i];
	}
	for (int j = 0; j < number - 1; j++)
	{
		for (int k = 0; k < number - j - 1; k++)
		{
			tab[k][j + 1] = tab[k + 1][j] - tab[k][j];
		}
	}
	long long s = tab[0][0];
	int y = (x - mas_x[0]) / (mas_x[1] - mas_x[0]);
	int ras = (x - mas_x[0]) / (mas_x[1] - mas_x[0]);
	for (int j = 1; j < number - 1; j++)
	{
		y /= j;
		s += (tab[0][j] * static_cast<long long>(y)) % m;
		y *= ras - j;
	}
	cout << s % m << endl;
	return s % m;
}

int main()
{
	mt19937 rng(123456);
	uniform_int_distribution <int> random(1, 100000);
	int a = random(rng);
	int d = random(rng);
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			mas_x[i] = a;
		}
		else
		{
			mas_x[i] = (mas_x[i - 1] + d) % m;
		}
		cout << "ask "<< mas_x[i] << endl;
		cout << polynom(mas_x[i]) << endl;
		fflush(stdout);
		cin >> mas_y[i];
		buff[i] = mas_y[i];
	}
	if (interpolation(mas_x, mas_y, 1, mas_x[1]) == buff[1] && interpolation(mas_x, mas_y, 1, mas_x[2]) == buff[2])
	{
		cout << "degree " << 0 << endl;
		return 0;
	}
	for (int i = 3; i < 13; i++)
	{
		mas_x[i] = (mas_x[i - 1] + d) % m;
		cout << "ask " << mas_x[i] << endl;
		cout << polynom(mas_x[i]) << endl;
		fflush(stdout);
		cin >> mas_y[i];
		buff[0] = mas_y[i - 2];
		buff[1] = mas_y[i - 1];
		buff[2] = mas_y[i];
		if (interpolation(mas_x, mas_y, i, mas_x[i - 1]) == buff[1] && interpolation(mas_x, mas_y, i, mas_x[i]) == buff[2])
		{
			cout << "degree "<< i - 2 << endl;
			return 0;
		}
		if (i == 12)
		{
			cout << "degree " << 10 << endl;
			return 0;
		}
	}
}
