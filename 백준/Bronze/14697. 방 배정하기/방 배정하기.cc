#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[5], dp[310];
int n;

int main()
{
	int i, j;
	scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
	dp[0] = 1;
	scanf("%d", &n);
	for (i = 0; i <= n; i++) {
		for (j = 0; j < 3; j++) {
			if (i >= arr[j]) dp[i] = max(dp[i], dp[i - arr[j]]);
		}
	}
	printf("%d", dp[n]);
	return 0;
}