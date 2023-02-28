#include <stdio.h>

int main()
{
	int l, r, d, c = 0;
	scanf_s("%d %d %d", &l, &r, &d);
	for (int i = l / d; i < r / d + 1; i++)
	{
		if (l <= d * i && d * i <= r)
		{
			printf("%d\n", d * i);
		}
	}
}