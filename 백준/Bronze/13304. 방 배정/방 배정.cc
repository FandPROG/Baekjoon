#include <stdio.h>

int low, mid_ma, mid_fe, high_ma, high_fe;
int n, k;

int main()
{
	int i, j;
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &y, &x);
		if (1 <= x && x <= 2) low++;
		else if (3 <= x && x <= 4) {
			if (y == 1) mid_ma++;
			else mid_fe++;
		}
		else if (5 <= x && x <= 6) {
			if (y == 1) high_ma++;
			else high_fe++;
		}
	}
	int ans = (low / k) + (mid_ma / k) + (mid_fe / k) + (high_ma / k) + (high_fe / k);
	if (low % k > 0) ans++;
	if (mid_ma % k > 0) ans++;
	if (mid_fe % k > 0) ans++;
	if (high_ma % k > 0) ans++;
	if (high_fe % k > 0) ans++;
	printf("%d", ans);
	return 0;
}