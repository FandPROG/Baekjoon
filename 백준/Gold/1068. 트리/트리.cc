#include <stdio.h>

int n, ch[55];
int p_node[55], res[55];
int par;
int che[55], an;

void dfs(int x)
{
	if (x == p_node[x]) {
		an = x;
		return;
	}
	else {
		ch[p_node[x]] = 1;
		che[x] = 1;
		dfs(p_node[x]);
	}
}

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (x == -1) {
			p_node[i] = i;
			par = i;
		}
		else p_node[i] = x;
	}
	int m;
	scanf("%d", &m);
	if (m == par) {
		printf("0");
		return 0;
	}
	p_node[m] = m;
	for (i = 0; i < n; i++) {
		dfs(i);
		res[i] = an;
		for (j = 0; j <= n; j++) che[j] = 0;
	}
	int ans = 0;
	for (i = 0; i < n; i++) {
		if (ch[i] == 0 && res[i] == par) {
			ans++;
		}	
	}
	printf("%d", ans);
	return 0;
}