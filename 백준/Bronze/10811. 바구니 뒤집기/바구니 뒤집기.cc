#include <stdio.h>

int n, m;
int arr[110];
int ans[110];

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) arr[i] = i;
	for (i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		int cnt = 0;
		for (j = x; j <= y; j++, cnt++) {
			ans[j] = arr[y - cnt];
		}
		for (j = x; j <= y; j++) {
			arr[j] = ans[j];
		}
	}
	for (i = 1; i <= n; i++) printf("%d ", arr[i]);
	return 0;
}