#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, c;
int arr[15];
int dp[1 << 13][10][20];

int BitDP(int vis, int bag, int cap)
{
	int i, j;
	if (vis == (1 << n) - 1) return 0;
	if (dp[vis][bag][cap] != 0) return dp[vis][bag][cap];
	for (i = 0; i < n; i++) {
		if ((vis & (1 << i)) != 0) continue;
		if (arr[i] > c) continue;
		if (bag + 1 >= m && cap + arr[i] > c) continue;
		if (cap + arr[i] > c) dp[vis][bag][cap] = max(dp[vis][bag][cap], BitDP(vis | (1 << i), bag + 1, arr[i]) + 1);
		else dp[vis][bag][cap] = max(dp[vis][bag][cap], BitDP(vis | (1 << i), bag, cap + arr[i]) + 1);
	}
	return dp[vis][bag][cap];
}

int main()
{
	int i, j;
	scanf("%d %d %d", &n, &m, &c);
	for (i = 0; i < n; i++) scanf("%d", &arr[i]);
	printf("%d", BitDP(0, 0, 0));
	return 0;
}