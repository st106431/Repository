#include <stdio.h>

int main()
{
	int s[100], n, k = 1, i = 0;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &s[i]);
	}
	while (k != 0)
	{
		k = 0;
		for (int j = 0; j < n; j++)
		{
			if (s[j] == i)
			{
				k++;
			}
		}
		i++;
	}
	printf("%d\n", i - 1);
}