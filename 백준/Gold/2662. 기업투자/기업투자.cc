#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int dp[310][30], arr[310][30];
int way[310][30], ans[30];

void dfs(int x, int y)
{
	if (way[x][y] == -1) {
		ans[y] += x;
		return;
	}
	else if (way[x][y] == -2) {
		dfs(x, y - 1);
	}
	else {
		int k = way[x][y];
		ans[y] += k;
		dfs(x - way[x][y], y - 1);
	}
}

int main()
{
	int i, j, k;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		for (j = 1; j <= m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (arr[i][j] > dp[i][j - 1]) {
				dp[i][j] = arr[i][j];
				way[i][j] = -1;
			}
			else {
				dp[i][j] = dp[i][j - 1];
				way[i][j] = -2;
			}
			for (k = 1; k < i; k++) {
				if (dp[i][j] < dp[i - k][j - 1] + arr[k][j]) {
					dp[i][j] = dp[i - k][j - 1] + arr[k][j];
					way[i][j] = k;
				}
			}
		}
	}
	dfs(n, m);
	printf("%d\n", dp[n][m]);
	for (i = 1; i <= m; i++) printf("%d ", ans[i]);
	return 0;
}