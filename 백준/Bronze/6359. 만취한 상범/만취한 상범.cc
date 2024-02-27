#include <stdio.h>

int main()
{
	int i, j;
	int t;
	scanf("%d", &t);
	while (t--) {
		int x;
		scanf("%d", &x);
		for (i = 1;; i++) {
			if (i * i > x) break;
		}
		printf("%d\n", i - 1);
	}
	return 0;
}