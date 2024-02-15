#include <stdio.h>
#include <vector>

using namespace std;

long long n, m;
long long sum[110], cosd[110], dp[110], vis[110];
vector <long long> ans;

void dfs(long long x)
{
	if (vis[x] == 0) return;
	else {
		ans.push_back(vis[x]);
		dfs(vis[x]);
	}
}

int main()
{
	long long i, j;
	scanf("%lld %lld", &n, &m);
	for (i = 0; i <= m + 1; i++) dp[i] = 2e19;
	for (i = 1; i <= m + 1; i++) {
		long long x;
		scanf("%lld", &x);
		sum[i] = sum[i - 1] + x;
	}
	dp[0] = 0;
	vis[0] = 0;
	for (i = 1; i <= m; i++) scanf("%lld", &cosd[i]);
	for (i = 0; i < m + 1; i++) {
		for (j = i + 1; j <= m + 1; j++) {
			if (sum[j] <= sum[i] + n) {
				if (dp[j] > dp[i] + cosd[i]) {
					dp[j] = dp[i] + cosd[i];
					vis[j] = i;
				}
			}
		}
	}
	dfs(m + 1);
	printf("%lld\n", dp[m + 1]);
	printf("%lld\n", ans.size());
	for (i = ans.size() - 1; i >= 0; i--) printf("%lld ", ans[i]);
	return 0;
}