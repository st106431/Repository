#include <stdio.h>

int main()
{
	int s[100], n, c, k = 1;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &s[i]);
	}
	c = s[0];
	for (int i = 0; i < n; i++)
	{
		if (c > s[i])
		{
			k++;
		}
	}
	printf("%d", k);
}