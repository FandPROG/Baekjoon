#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int par[310];
int n;
int w[310];
int ch[310];

struct dat {
	int x, y, val;
};

bool comp(dat a, dat b)
{
	return a.val < b.val;
}

vector <dat> vec;

int ffind(int x)
{
	if (x == par[x]) return x;
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
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		par[i] = i;
		scanf("%d", &w[i]);
		vec.push_back({ 0, i, w[i] });
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			int x;
			scanf("%d", &x);
			if (i < j) vec.push_back({ i, j, x });
		}
	}
	sort(vec.begin(), vec.end(), comp);
	int ans = 0;
	for (i = 0; i < vec.size(); i++) {
		int x = vec[i].x, y = vec[i].y, val = vec[i].val;
		int a = ffind(x), b = ffind(y);
		if (a == b) continue;
		funion(a, b);
		ans += val;
	}
	printf("%d", ans);
	return 0;
}