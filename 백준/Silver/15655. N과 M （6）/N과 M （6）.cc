#include <stdio.h>
#include <algorithm> 

using namespace std;

int n, m;
int arr[10];
int ans[10];

void DFS(int idx, int x)
{
	int i;
	if (x >= m) {
		for (i = 0; i < m; i++) printf("%d ", ans[i]);
		printf("\n");
		return;
	}
	for (i = idx; i < n; i++) {
		ans[x] = arr[i];
		DFS(i + 1, x + 1);
	}
}

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) scanf("%d", &arr[i]);
	sort(arr, arr + n);
	DFS(0, 0);
	return 0;
}