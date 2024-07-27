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

int n, m;
int par[500010];
int ch[500010];
vector <dat> vec;

int ffind(int x) {
	if (x == par[x]) return x;
	else return par[x] = ffind(par[x]);
}

void funion(int x, int y) {
	int a = ffind(x), b = ffind(y);
	if (a < b) par[a] = b;
	else par[b] = a;
}

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) par[i] = i;
	for (i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		vec.push_back({ x, y, z });
	}
	sort(vec.begin(), vec.end(), comp);
	for (i = 0; i < vec.size(); i++) {
		int x = vec[i].x, y = vec[i].y;
		int val = vec[i].val;
		int a = ffind(x), b = ffind(y);
		if (a == b) continue;
		else {
			funion(a, b);
			if(val <= n) ch[val] = 1;
		}
	}
	for (i = 1; i <= n; i++) {
		if (ch[i] == 0) {
			printf("%d", i);
			break;
		}
	}
	return 0;
}