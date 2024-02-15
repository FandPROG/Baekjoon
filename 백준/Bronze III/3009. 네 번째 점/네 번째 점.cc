#include <stdio.h>

int x[1010], y[1010];

int main()
{
	for (int i = 0; i < 3; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		x[a]++;
		y[b]++;
	}
	int ans_x, ans_y;
	for (int i = 1; i <= 1000; i++) {
		if (x[i] == 1) ans_x = i;
		if (y[i] == 1) ans_y = i;
	}
	printf("%d %d", ans_x, ans_y);
	return 0;
}