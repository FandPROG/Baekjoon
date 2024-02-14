#include <stdio.h>

int n, m;
int arr[110][110];

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			int x;
			scanf("%d", &x);
			arr[i][j] += x;
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			int x;
			scanf("%d", &x);
			arr[i][j] += x;
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}