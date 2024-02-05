#include <stdio.h>

int n, m;
int arr[10010];

int pandas(int x)
{
	int i, sum = 0;
	for (i = 0; i < n; i++) {
		if (arr[i] > x) sum += x;
		else sum += arr[i];
	}
	return sum;
}

int main()
{
	int i, j;
	int low = 1, high = -2e9;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (high < arr[i]) high = arr[i];
	}
	scanf("%d", &m);
	while (low <= high) {
		int mid = (low + high) / 2;
		int mid_res = pandas(mid);
		if (mid_res <= m) low = mid + 1;
		else high = mid - 1;
	}
	printf("%d", low - 1);
	return 0;
}