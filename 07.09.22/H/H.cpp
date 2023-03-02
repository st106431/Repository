#include <stdio.h>

int main()
{
	int s[100], n, m = 0, x, h;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &s[i]);
	}
	for (int i = 0; i < n; i++)
	{
		x = 0;
		for (int j = 0; j < n; j++)
		{
			if (s[i] == s[j])
			{
				x++;
			}
		}
		if (x > m)
		{
			m = x;
			h = s[i];
		}
	}
	printf("%d", h);
}