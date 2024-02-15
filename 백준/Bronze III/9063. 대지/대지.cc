#include <stdio.h>

int n;
int mn_x = 2e9, mx_x = -2e9;
int mn_y = 2e9, mx_y = -2e9;

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		if (x < mn_x) mn_x = x;
		if (x > mx_x) mx_x = x;
		if (y < mn_y) mn_y = y;
		if (y > mx_y) mx_y = y;
	}
	printf("%d", (mx_x - mn_x) * (mx_y - mn_y));
	return 0;
}