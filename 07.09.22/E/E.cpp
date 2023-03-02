#include <stdio.h>

int main()
{
	char s[100]{' '};
	int a[100]{ 0 };
	char c;
	int k = 0, h = 0, w = 0;
	fgets(s, 100, stdin);
	while (s[w] != '\0' && w < 100)
	{
		w++; 
	}
	c = s[0];
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (s[j] == s[i])
			{
				a[i]++;
			}
		}
	}
	for (int i = 0; i < w; i++)
	{
		if (a[i] > k)
		{
			k = a[i];
			h = i;
		}
	}
	printf("%c\n", s[h]);
}
