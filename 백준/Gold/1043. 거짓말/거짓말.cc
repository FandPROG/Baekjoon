#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int par[110];
vector<int> L;
vector<int> vec[110];

int ffind(int x)
{
	if (x == par[x]) return x;
	else return par[x] = ffind(par[x]);
}

void funion(int x, int y)
{
	int a = ffind(x);
	int b = ffind(y);
	if (a == b) return;
	else par[b] = a;
}

int main()
{
	int i, j;
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (i = 1; i <= n; i++) par[i] = i;
	for (i = 0; i < k; i++) {
		int x;
		scanf("%d", &x);
		L.push_back(x);
	}
	for (i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		for (j = 0; j < x; j++) {
			int y;
			scanf("%d", &y);
			vec[i].push_back(y);
		}
		for (j = 0; j < x - 1; j++) {
			funion(vec[i][j], vec[i][j + 1]);
		}
	}
	int ans = 0;
	for (i = 0; i < m; i++) {
		int che = 0;
		for (j = 0; j < vec[i].size(); j++) {
			for (int l = 0; l < k; l++) {
				if (ffind(L[l]) == ffind(vec[i][j])) che = 1;
			}
		}
		if (che == 0) ans++;
	}
	printf("%d", ans);
	return 0;
}