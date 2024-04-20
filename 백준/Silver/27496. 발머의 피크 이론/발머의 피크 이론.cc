#include <stdio.h>

int n, l;
int arr[1010010];

int main()
{
	int i;
	scanf("%d %d", &n, &l);
	for (i = 0; i < n; i++) scanf("%d", &arr[i]);
	int sum = 0, ans = 0;
	int low = 0, high = 0;
	while (high < n) {
		sum += arr[high++];
		if (high - low > l) sum -= arr[low++];
		if (129 <= sum && sum <= 138) ans++;
	}
	printf("%d", ans);
	return 0;
}