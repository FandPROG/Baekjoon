#include <stdio.h>

int n, k;
int arr[15];

int main()
{
	int i, j;
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++) scanf("%d", &arr[i]);
	int ans = 0;
	for (i = n - 1; i >= 0; i--) {
		if (k >= arr[i]) {
			ans += k / arr[i];
			k %= arr[i];
		}
	}
	printf("%d", ans);
	return 0;
}