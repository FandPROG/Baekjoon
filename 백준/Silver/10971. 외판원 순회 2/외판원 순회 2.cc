#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int arr[15][15], dp[1 << 11][11];

int tsp(int vis, int x)
{
	int i, j;
	if (vis == (1 << n) - 1) {
		if (arr[x][i] > 0) return arr[x][0];
		else return 2e9;
	}
	if (dp[vis][x] != 0) return dp[vis][x];
	dp[vis][x] = 2e9;
	for (i = 0; i < n; i++) {
		if ((vis & (1 << i)) == 0 && arr[x][i] > 0) {
			dp[vis][x] = min(dp[vis][x], tsp((vis | (1 << i)), i) + arr[x][i]);
		}
	}
	return dp[vis][x];
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
	printf("%d", tsp(1, 0));
	return 0;
}