#include <stdio.h>

int n;

int main()
{
	int x, y;
	scanf("%d %d %d", &n, &x, &y);
	int cnt = 1;
	while (1) {
		if (x % 2) x++;
		if (y % 2) y++;
		x /= 2, y /= 2;
		if (x == y) break;
		cnt++;
	}
	printf("%d", cnt);
	return 0;
}