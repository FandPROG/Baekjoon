#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct dat {
	int x, y, val;
};

bool comp(dat a, dat b) {
	return a.val < b.val;
}

int n, w;
char s[1010];
vector <dat> vec;
int m, par[1010];

int ffind(int x) {
	if (x == par[x]) return x;
	else return par[x] = ffind(par[x]);
}

void funion(int x, int y) {
	int a = ffind(x), b = ffind(y);
	if (a < b) par[b] = a;
	else par[a] = b;
	return;
}

int main()
{
	int i, j;
	scanf("%d %d", &n, &w);
	for (i = 1; i <= n; i++) par[i] = i;
	for (i = 1; i <= n; i++) scanf(" %c", &s[i]);
	for (i = 0; i < w; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		if (s[x] == s[y]) continue;
		vec.push_back({ x, y, z });
	}
	m = vec.size();
	int ans = 0;
	sort(vec.begin(), vec.end(), comp);
	for (i = 0; i < m; i++) {
		int x = vec[i].x, y = vec[i].y, val = vec[i].val;
		int a = ffind(x), b = ffind(y);
		if (a == b) continue;
		funion(x, y);
		ans += val;
	}
	for (i = 1; i <= n; i++) ffind(i);
	for (i = 1; i < n; i++) {
		if (par[i] != par[i + 1]) {
			printf("-1");
			return 0;
		}
	}
	printf("%d", ans);
	return 0;
}