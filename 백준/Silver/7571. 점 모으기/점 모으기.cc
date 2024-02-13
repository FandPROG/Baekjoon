#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int n, m;
long long x[100010], y[100010];

int main()
{
	int i;
	long long sum_x = 0, sum_y = 0;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) scanf("%lld %lld", &x[i], &y[i]);
	sort(x, x + m);
	sort(y, y + m);
	sum_x = x[m / 2];
	sum_y = y[m / 2];
	long long ans = 0;
	for (i = 0; i < m; i++) {
		ans += (abs(sum_x - x[i]) + abs(sum_y - y[i]));
	}
	printf("%lld", ans);
	return 0;
}