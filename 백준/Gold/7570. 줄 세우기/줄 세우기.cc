#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int dp[1000010];
int ans = -2e9;

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		dp[x] = dp[x - 1] + 1;
		ans = max(ans, dp[x]);
	}
	printf("%d", n - ans);
	return 0;
}