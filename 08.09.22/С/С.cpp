#include <stdio.h>
int k[100], n, a, s = 0, numb = 0, pr = 1;

int t (int w, int c)
{
	int p = 0, g = 1, l = 0;
	do 
	{
		k[l++] = w % c;
		w /= c;
	} while (w != 0);
	for (int i = 0; i < l; i++) 
	{
		p += k[i] * g;
		g *= 10;
	}
	return p;
}

int main()
{
	scanf_s("%d", &n);
	a = n;
	while (a != 0)
	{
		a /= 10;
		numb++;
	}
	for (int i = 0; i < numb; i++)
	{
		s += (n % 10) * pr;
		pr *= 5;
		n /= 10;
	}
	//printf("%d\n", s);
	a = t(s, 7), s = 0;
	while (a > 0)
	{
		s += a % 10;
		a /= 10;
	}
	printf("%d\n", t(s,3));
}
