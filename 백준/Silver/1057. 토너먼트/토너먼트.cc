#include <stdio.h>

int main()
{
	int i, n, a, b;
	scanf("%d %d %d", &n, &a, &b);
	for (i = 1;; i++) {
		if (i > n) {
			printf("-1");
			return 0;
		}
		if (a % 2) a++;
		if (b % 2) b++;
		a /= 2;
		b /= 2;
		if (a == b) break;
	}
	printf("%d", i);
	return 0;
}