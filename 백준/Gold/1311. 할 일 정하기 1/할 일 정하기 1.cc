#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n;
int arr[25][25];
int dp[21][1 << 21];

int dpinit(int c, int vis)
{
	int i, j;
	if (vis == (1 << n) - 1) return 0;
	if (dp[c][vis] != -2e9) return dp[c][vis];
	dp[c][vis] = 2e9;
	for (i = 0; i < n; i++) {
		if ((vis & (1 << i))) continue;
		dp[c][vis] = min(dp[c][vis], dpinit(c + 1, vis | (1 << i)) + arr[c][i]);
	}
	return dp[c][vis];
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
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 1 << 20; j++) {
			dp[i][j] = -2e9;
		}
	}
	printf("%d", dpinit(0, 0));
	return 0;
}