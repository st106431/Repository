#include <stdio.h>

int main()
{
	char s[200], d[200];
	int w = 0, r = 0;
	fgets(s, 102, stdin);
	fgets(d, 102, stdin);
	while (s[w] != '\0' && s[w] != '\n')
	{
		w++;
	}
	while (d[r] != '\0' && d[r] != '\n')
	{
		r++;
	}
	//printf("%d\n", w);
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < r; j++)
		{
			if (s[i] == d[j])
			{
				s[i] = 0;
			}
		}
	}
	for (int i = 0; i < w; i++)
	{
		if (s[i] != 0)
		{
			printf("%c", s[i]);
		}
	}
}
