#include <stdio.h>
#include <algorithm>

using namespace std;

long long n;
long long val[100010], way[100010];
long long ans;

int main()
{
	long long i, j;
	scanf("%lld", &n);
	for (i = 1; i < n; i++) scanf("%lld", &way[i]);
	for (i = 1; i <= n; i++) scanf("%lld", &val[i]);
	long long mn = 2e9;
	for (i = 1; i < n; i++) {
		mn = min(mn, val[i]);
		ans += mn * way[i];
	}
	printf("%lld", ans);
	return 0;
}