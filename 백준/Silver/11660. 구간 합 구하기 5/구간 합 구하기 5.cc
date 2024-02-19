#include <stdio.h>

int sum[1025][1025];
int n, t;

int main()
{
	int i, j;
	scanf("%d %d", &n, &t);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			int x;
			scanf("%d", &x);
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + x;
		}
	}
	while (t--) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n", sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1]);
	}
	return 0;
}