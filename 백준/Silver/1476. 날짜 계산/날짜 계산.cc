#include <stdio.h>

int main()
{
	int i;
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	for (i = 1;; i++) {
		int x = i % 15, y = i % 28, z = i % 19;
		if (x == 0) x = 15;
		if (y == 0) y = 28;
		if (z == 0) z = 19;
		if (x == a && y == b && z == c) {
			printf("%d", i);
			break;
		}
	}
	return 0;
}