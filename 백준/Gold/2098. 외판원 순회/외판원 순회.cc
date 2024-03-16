#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int arr[20][20];
int dp[1 << 20][20];

int TSP(int vis, int c)
{
	int i, j;
	vis |= (1 << c);
	if (vis == (1 << n) - 1) {
		if (arr[c][0] > 0) {
			return arr[c][0];
		}
		else return 2e9;
	}
	if (dp[vis][c] > 0) return dp[vis][c];
	dp[vis][c] = 2e9;
	for (i = 0; i < n; i++) {
		if (i != c && (vis & (1 << i)) == 0 && arr[c][i] > 0) {
			int res = TSP(vis, i) + arr[c][i];
			if (dp[vis][c] > res) dp[vis][c] = res;
		}
	}
	return dp[vis][c];
}

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	int ans = TSP(0, 0);
	if (ans == 2e9) printf("-1\n");
	else printf("%d", ans);
	return 0;
}