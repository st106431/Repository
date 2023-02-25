#include <stdio.h>

int main()
{
	int a, b, d;
	scanf_s("%d %d %d", &a, &b, &d);
	if (a <= b)
	{
		if (d < b - a)
		{
			printf("%d\n", a + d);
		}
		else
		{
			printf("%d\n", b);
		}
	}
	else
	{
		if (d < a - b)
		{
			printf("%d\n", a - d);
		}
		else
		{
			printf("%d\n", b);
		}
	}
}

