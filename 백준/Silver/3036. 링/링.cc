#include <stdio.h>

int n;
int first;

int GCD(int a, int b)
{
	if (b == 0) return a;
	else return GCD(b, a % b);
}

int main()
{
	int i, j;
	scanf("%d %d", &n, &first);
	for (i = 0; i < n - 1; i++) {
		int x, y = first;
		scanf("%d", &x);
		while (1) {
			int gc;
			if (x > y) gc = GCD(x, y);
			else gc = GCD(y, x);
			if (gc == 1) break;
			x /= gc;
			y /= gc;
		}
		printf("%d/%d\n", y, x);
	}
	return 0;
}