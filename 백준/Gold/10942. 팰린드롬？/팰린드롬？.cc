#include <stdio.h>
#include <algorithm>

using namespace std;

int n, m;
int arr[2010];
int dp[2010][2010];

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &arr[i]);
	for (i = 1; i <= n; i++) dp[i][i] = 1;
	for (i = 1; i < n; i++) if (arr[i] == arr[i + 1]) dp[i][i + 1] = 1;
	for (i = n; i >= 1; i--) {
		for (j = i + 1; j <= n; j++) {
			if (arr[i] == arr[j] && dp[i + 1][j - 1] == 1) dp[i][j] = 1;
		}
	}
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%d\n", dp[x][y]);
	}
	return 0;
}