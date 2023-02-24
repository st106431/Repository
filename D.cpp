#include <iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

int m = 1000000007;
int mas_x[13]{ 0 };
int mas_y[13]{ 0 };
int tab[13][13]{ 0 };
int buff[3]{ 0 };

int interpolation(int mas_x[13], int mas_y[13], int number, int x)
{
	for (int i = 0; i < number; i++)
	{
		tab[i][0] = mas_y[i];
	}
	for (int j = 0; j < number - 1; j++)
	{
		for (int k = 0; k < number - j - 1; k++)
		{
			tab[k][j + 1] = (tab[k + 1][j] - tab[k][j]) % m;
		}
	}
	int s = tab[0][0];
	int y = (x - mas_x[0]) / (mas_x[1] - mas_x[0]);
	int ras = (x - mas_x[0]) / (mas_x[1] - mas_x[0]);
	for (int j = 1; j < number - 1; j++)
	{
		y /= j;
		s += (tab[0][j] * y) % m;
		y *= (ras - j) % m;
	}
	return s;
}

int main()
{
	for (int i = 0; i < 3; i++)
	{
		mas_x[i] = i;
		cout << "ask "<< mas_x[i] << endl;
		fflush(stdout);
		cin >> mas_y[i];
		buff[i] = mas_y[i];
	}
	if (interpolation(mas_x, mas_y, 1, 1) == buff[1] && interpolation(mas_x, mas_y, 1, 2) == buff[2])
	{
		cout << "degree " << 0 << endl;
		return 0;
	}
	for (int i = 3; i < 13; i++)
	{
		mas_x[i] = i;
		cout << "ask " << mas_x[i] << endl;
		fflush(stdout);
		cin >> mas_y[i];
		buff[0] = mas_y[i - 2];
		buff[1] = mas_y[i - 1];
		buff[2] = mas_y[i];
		if (interpolation(mas_x, mas_y, i, i - 1) == buff[1] && interpolation(mas_x, mas_y, i, i) == buff[2])
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