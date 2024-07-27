#include <stdio.h>
#include <algorithm>

int n, m;
int ans[10];

void DFS(int x, int l) {
	if (l == m) {
		for (int i = 0; i < l; i++) printf("%d ", ans[i]);
		printf("\n");
		return;
	}
	else if (x == n + 1) return;
	ans[l] = x;
	DFS(x + 1, l + 1);
	DFS(x + 1, l);
	return;
}

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	DFS(1, 0);
	return 0;
}