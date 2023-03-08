#include <stdio.h>

int main()
{
	char s[200], d[200];
	int k, n;
	int h = 0, w = 0;
	int l[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
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
	for (int i = 0; i < 26; i++)
	{
		for(int j = 0; j < h; j++)
		{
			if (d[j] == l[i])
			{
				printf("%c\n", d[j]);
			}
		}
	}
}