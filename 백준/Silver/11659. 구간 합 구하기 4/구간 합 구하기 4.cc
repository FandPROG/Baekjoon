#include <stdio.h>

int n, t;
int sum[100010];

int main()
{
	int i, j;
	scanf("%d %d", &n, &t);
	for (i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		sum[i] = sum[i - 1] + x;
	}
	while (t--) {
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%d\n", sum[y] - sum[x - 1]);
	}
	return 0;
}