#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int n, m;

int dp[10010][110];

int Div(int x, int y)
{
	int i, j;
	if (x == y) return dp[x][y] = 1;
	if (x < 0 || y < 0) return 2e9;
	if (dp[x][y] != -1) return dp[x][y];
	dp[x][y] = x * y;
	if (x >= 3 * y) dp[x][y] = min(dp[x][y], Div(x - y, y) + 1);
	else {
		for (i = 1; i <= (y + 1) / 2; i++) dp[x][y] = min(dp[x][y], Div(x, i) + Div(x, y - i));
		for (i = 1; i <= (x + 1) / 2; i++) dp[x][y] = min(dp[x][y], Div(i, y) + Div(x - i, y));
	}
	return dp[x][y];
}

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= m; j++) {
			dp[i][j] = -1;
		}
	}
	int res = Div(n, m);
	printf("%d", res);
	return 0;
}