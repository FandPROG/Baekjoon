#include <stdio.h>
#include <algorithm>

using namespace std;

long long dp[100010][5];
long long arr[100010];
long long n;

int main()
{
	long long i, j;
	scanf("%lld", &n);
	for (i = 1; i <= n; i++) scanf("%lld", &arr[i]);
	for (i = 1; i <= n; i++) {
		dp[i][0] = max(arr[i], dp[i - 1][0] + arr[i]);
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
	}
	dp[1][1] = arr[1];
	long long ans = -2e9;
	for (i = 1; i <= n; i++) {
		ans = max(ans, max(dp[i][0], dp[i][1]));
	}
	printf("%lld", ans);
	return 0;
}