#include <stdio.h>
#include <algorithm>

int n, k, sum, arr[55];
double ans;

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &arr[i]), sum += arr[i];
	scanf("%d", &k);
	if (n == 1 || k == 1) {
		printf("1.0");
		return 0;
	}
	double now = 1;
	for (i = 0; i < n; i++) {
		for (j = 0; j < k; j++) {
			now *= ((double)arr[i] - j) / ((double)sum - j);
		}
		ans += now;
		now = 1;
	}
	printf("%.16lf", ans);
	return 0;
}