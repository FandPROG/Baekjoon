#include <stdio.h>
#include <algorithm>

using namespace std;

int n, k;
int arr[110];
int dp[10010];

int main()
{
	int i, j;
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++) scanf("%d", &arr[i]);
	for (i = 1; i <= k; i++) dp[i] = 2e9;
	for (i = 1; i <= k; i++) {
		for (j = 0; j < n; j++) {
			if (i >= arr[j]) dp[i] = min(dp[i], dp[i - arr[j]] + 1);
		}
	}
	if (dp[k] >= 2e9) printf("-1");
	else printf("%d", dp[k]);
	return 0;
}