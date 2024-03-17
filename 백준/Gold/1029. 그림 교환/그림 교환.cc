#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int arr[20][20];
int dp[16][10][1 << 16];

int memo(int x, int val, int vis)
{
	int i, j;
	if (dp[x][val][vis] != 0) return dp[x][val][vis];
	for (i = 1; i < n; i++) {
		if (i != x && (vis & (1 << i)) == 0 && arr[x][i] >= val) {
			dp[x][val][vis] = max(dp[x][val][vis], memo(i, arr[x][i], vis | (1 << i)) + 1);
		}
	}
	return dp[x][val][vis];
}

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	printf("%d", memo(0, 0, 0) + 1);
	return 0;
}