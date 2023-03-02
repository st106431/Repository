#include <stdio.h>

int main()
{
	int l, r, d, w;
	scanf("%d %d %d", &l, &r, &d);
	w = l % d;
	if (w != 0)

		l += d - w;

	while (l <= r)
	{
		printf("%d ", l);
		l += d;
	}
}