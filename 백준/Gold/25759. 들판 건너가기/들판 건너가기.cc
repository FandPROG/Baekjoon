#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[100010];
int n;
int arr[100010];
int nmx[110];

int main()
{
	int i, j;
	for (i = 0; i <= 100; i++) nmx[i] = -1;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &arr[i]);
	for (i = 0; i < n; i++) {
		for (j = 1; j <= 100; j++) {
			if (nmx[j] == -1) continue;
			dp[i] = max(dp[i], nmx[j] + (arr[i] - j) * (arr[i] - j));
		}
		nmx[arr[i]] = max(nmx[arr[i]], dp[i]);
	}
	printf("%d", dp[n - 1]);
	return 0;
}