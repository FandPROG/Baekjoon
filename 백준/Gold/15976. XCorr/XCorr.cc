#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

long long n, m;
long long vx_idx[300010], vx_val[300010];
long long vy_idx[300010], vy_val[300010], sumy[300010];
long long a, b;

int main()
{
	long long i, j;
	scanf("%lld", &n);
	for (i = 1; i <= n; i++) scanf("%lld %lld", &vx_idx[i], &vx_val[i]);
	scanf("%lld", &m);
	for (i = 1; i <= m; i++) scanf("%lld %lld", &vy_idx[i], &vy_val[i]);
	for (i = 1; i <= m; i++) sumy[i] = sumy[i - 1] + vy_val[i];
	scanf("%lld %lld", &a, &b);
	long long ans = 0;
	for (i = 1; i <= n; i++) {
		long long idx = vx_idx[i], val = vx_val[i];
		long long low = lower_bound(vy_idx + 1, vy_idx + m + 1, idx + a) - (vy_idx);
		long long high = lower_bound(vy_idx + 1, vy_idx + m + 1, idx + b) - (vy_idx);
		if (high > m) high--;
		if (vy_idx[high] > idx + b) high--;
		ans += val * (sumy[high] - sumy[low - 1]);
	}
	printf("%lld", ans);
	return 0;
}