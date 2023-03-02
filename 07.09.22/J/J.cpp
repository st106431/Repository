#include <stdio.h>

void sort(int s[50], int n, int c)
{
	while (n--)
	{
		bool w = 0;
		for (int i = 0; i < n; i++)
		{
			if (c * (s[i] - s[i + 1]) > 0)
			{
				int t = s[i + 1];
				s[i + 1] = s[i];
				s[i] = t;
				w = 1;
			}
		}
		if (w == 0)
		{
			break;
		}
	}
}

int main()
{
	int s[50], d[50], n, k = 1;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		if (i < n / 2)
		{
			scanf_s("%d", &s[i]);
		}
		else
		{
			scanf_s("%d", &d[i - n / 2]);
		}
	}
	sort(s, n / 2, 1);
	sort(d, n / 2, -1);
	for (int i = 0; i < n; i++)
	{
		if (i < n / 2)
		{
			printf("%d\n", s[i]);
		}
		else
		{
			printf("%d\n", d[i - n / 2]);
		}
	}
}