#include <stdio.h>

int v, e;
int ed[3010];
int par[3010];

int ffind(int x)
{
	if (x == par[x]) return x;
	else return par[x] = ffind(par[x]);
}

void funion(int x, int y)
{
	int a = ffind(x), b = ffind(y);
	if (a < b) par[b] = a;
	else par[a] = b;
}

int main()
{
	int i, j;
	scanf("%d %d", &v, &e);
	for (i = 1; i <= v; i++) par[i] = i;
	for (i = 0; i < e; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		funion(x, y);
		ed[x]++;
		ed[y]++;
	}
	int cnt = 0;
	for (i = 1; i <= v; i++) {
		if (ed[i] % 2 == 1) {
			cnt++;
		}
	}
	for (i = 1; i < v; i++) {
		if (ffind(i) == ffind(i + 1)) continue;
		else {
			printf("NO");
			return 0;
		}
	}
	if (cnt == 2 || cnt == 0) printf("YES");
	else printf("NO");
	return 0;
}