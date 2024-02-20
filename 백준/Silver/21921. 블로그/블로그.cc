#include <stdio.h>

int n, x;
int arr[250010];

int main()
{
	int i, j;
	scanf("%d %d", &n, &x);
	for (i = 0; i < n; i++) scanf("%d", &arr[i]);
	int sum = 0, low = 0, high = x;
	for (i = 0; i < x; i++) sum += arr[i];
	int ans = sum;
	while (high < n) {
		sum -= arr[low++];
		sum += arr[high++];
		if (sum > ans) ans = sum;
	}
	int cnt = 0;
	sum = 0, low = 0, high = x;
	for (i = 0; i < x; i++) sum += arr[i];
	if (sum == ans) cnt++;
	while (high < n) {
		sum -= arr[low++];
		sum += arr[high++];
		if (sum == ans) cnt++;
	}
	if (ans == 0) printf("SAD");
	else printf("%d\n%d", ans, cnt);
	return 0;
}