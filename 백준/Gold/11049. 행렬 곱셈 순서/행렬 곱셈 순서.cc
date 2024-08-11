#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int r[510], c[510];
int dp[510][510];

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= n; j++) {
			dp[i][j] = 2e9;
		}
	}
	for (i = 0; i <= n; i++) dp[i][i] = 0;
	for (i = 1; i <= n; i++) scanf("%d %d", &r[i], &c[i]);
	for (i = 1; i < n; i++) {
		for (j = 1; j + i <= n; j++) {
			int s = j;
			int e = i + j;
			for (int k = s; k < e; k++) {
				dp[s][e] = min(dp[s][e], dp[s][k] + dp[k + 1][e] + (r[s] * c[k] * c[e]));
			}
		}
	}
	printf("%d", dp[1][n]);
	return 0;
}