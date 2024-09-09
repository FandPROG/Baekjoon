#include <stdio.h>
#include <algorithm>

int n, m, k = 2e9;

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		if (k > y - x + 1) k = y - x + 1;
	}
	int num = 1;
	for (i = 0; i < n; i++) {
		printf("%d ", num++);
		if (num > k) num = 1;
	}
	return 0;
}