#include <stdio.h>

int a, b;
int c, d;

int GCD(int x, int y)
{
	if (y == 0) return x;
	else return GCD(y, x % y);
}

int main()
{
	int i, j;
	scanf("%d %d", &a, &b);
	scanf("%d %d", &c, &d);
	int x = (a * d) + (c * b);
	int y = d * b;
	while (1)
	{
		int gc;
		if (x > y) gc = GCD(x, y);
		else gc = GCD(y, x);
		if (gc == 1) break;
		x /= gc;
		y /= gc;
	}
	printf("%d %d", x, y);
	return 0;
}