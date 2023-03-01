#include <stdio.h>

int main()
{
	int s[100], n, k = 0;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &s[i]);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (s[i] == s[j])
			{
				s[i] = s[j] = 0;
			}
		}
	}
	while (s[k] == 0)
	{
		k++;
	}
	printf("%d\n", s[k]);
}
