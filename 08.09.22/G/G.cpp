#include <stdio.h>

int main()
{
	char s[103], d[103];
	int k, n;
	int h = 0, w = 0;
	fgets(s, 102, stdin);
	scanf_s("%d", &k);
	while (s[w] != '\0' && s[w] != '\n')
	{
		w++;
	}
	for (int i = 0; i < w; i++)
	{
		n = 0;
		for (int j = 0; j <= i; j++)
		{
			if (s[j] == s[i])
			{
				n++;
			}
		}
		if (n == k)
		{
			d[h] = s[i];
			h++;
		}
	}
	for (int i = 0; i < h; i++)
	{
		printf("%c", d[i]);
	}
}