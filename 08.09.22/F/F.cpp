#include <stdio.h>

int main()
{
	char s[101], d[101];
	int w = 0, r = 0;
	fgets(s, 101, stdin);
	fgets(d, 101, stdin);
	while (s[w] != '\0')
	{
		w++;
	}
	while (d[r] != '\0')
	{
		r++;
	}
	for (int i = 0; i < w - 1; i++)
	{
		for (int j = 0; j < r - 1; j++)
		{
			if (s[i] == d[j])
			{
				s[i] = 0;
			}
		}
	}
	for (int i = 0; i < w - 1; i++)
	{
		if (s[i] != 0)
		{
			printf("%c", s[i]);
		}
	}
}
