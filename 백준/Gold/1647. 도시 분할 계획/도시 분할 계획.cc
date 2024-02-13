#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct xyz
{
	int x, y, cost;
};

bool comp(xyz a, xyz b)
{
	return a.cost < b.cost;
}

int n, m;
int par[100010];
vector <xyz> vec;

int ffind(int x)
{
	if (par[x] == x) return x;
	else return par[x] = ffind(par[x]);
}

void funion(int x, int y)
{
	int a = ffind(x);
	int b = ffind(y);
	if (a < b) par[b] = a;
	else par[a] = b;
	return;
}

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		vec.push_back({ x, y, z });
	}
	sort(vec.begin(), vec.end(), comp);
	for (i = 1; i <= n; i++) par[i] = i;
	int ans = 0, mx = -2e9;
	for (i = 0; i < m; i++) {
		if (ffind(vec[i].x) == ffind(vec[i].y)) continue;
		else {
			funion(vec[i].x, vec[i].y);
			ans += vec[i].cost;
			mx = (mx, vec[i].cost);
		}
	}
	printf("%d", ans - mx);
	return 0;
}