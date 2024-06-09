#include <stdio.h>

int n, m;
int arr[110];

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &arr[i]);
	scanf("%d", &m);
	for (j = 0; j < m; j++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a == 1) {
			for (i = b; i <= n; i += b) {
				if (arr[i] == 1) arr[i] = 0;
				else arr[i] = 1;
			}
		}
		else {
			int low = b - 1, high = b + 1;
			if (arr[b] == 0) arr[b] = 1;
			else arr[b] = 0;
			while (low > 0 && high <= n) {
				if (arr[low] != arr[high]) break;
				if (arr[low] == 1) arr[low] = 0;
				else arr[low] = 1;
				low--;
				if (arr[high] == 1) arr[high] = 0;
				else arr[high] = 1;
				high++;
			}
		}
	}
	int cnt = 0;
	for (i = 1; i <= n; i++) {
		cnt++;
		printf("%d ", arr[i]);
		if (cnt >= 20) {
			printf("\n");
			cnt = 0;
		}
	}
	return 0;
}