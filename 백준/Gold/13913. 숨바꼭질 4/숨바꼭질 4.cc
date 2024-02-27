#include <stdio.h>
#include <vector>

using namespace std;

int n, k;
int dp[100010];
int way[100010];
vector<int> ans;

void dfs(int x)
{
	ans.push_back(x);
	if (way[x] == x) return;
	else dfs(way[x]);
}

int main()
{
	int i, j;
	scanf("%d %d", &n, &k);
	dp[n] = 0;
	way[n] = n;
	for (i = n - 1; i >= 0; i--) {
		dp[i] = dp[i + 1] + 1;
		way[i] = i + 1;
	}
	for (i = n + 1; i <= k; i++) {
		dp[i] = dp[i - 1] + 1;
		way[i] = i - 1;
		if (i % 2 == 0) {
			if (dp[i] > dp[i / 2] + 1) {
				dp[i] = dp[i / 2] + 1;
				way[i] = i / 2;
			}
		}
		else {
			if (dp[i] > dp[(i + 1) / 2] + 2) {
				dp[i] = dp[(i + 1) / 2] + 2;
				way[i] = i + 1;
				way[i + 1] = (i + 1) / 2;
			}
		}
	}
	printf("%d\n", dp[k]);
	dfs(k);
	for (i = ans.size() - 1; i >= 0; i--) printf("%d ", ans[i]);
	return 0;
}