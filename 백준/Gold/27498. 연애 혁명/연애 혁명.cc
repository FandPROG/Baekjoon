#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int par[10010];

struct dat {
	int x, y, val;
};

bool comp(dat a, dat b)
{
	return a.val > b.val;
}

vector <dat> vec;

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
}

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) par[i] = i;
	int sum = 0;
	for (i = 0; i < m; i++) {
		int x, y, z, jud;
		scanf("%d %d %d %d", &x, &y, &z, &jud);
		if (jud == 1) funion(ffind(x), ffind(y));
		else sum += z, vec.push_back({ x, y, z });
	}
	int ans = 0;
	sort(vec.begin(), vec.end(), comp);
	for (i = 0; i < vec.size(); i++) {
		int x = vec[i].x, y = vec[i].y;
		int val = vec[i].val;
		int a = ffind(x), b = ffind(y);
		if (a == b) continue;
		funion(x, y);
		ans += val;
	}
	printf("%d", sum - ans);
	return 0;
}