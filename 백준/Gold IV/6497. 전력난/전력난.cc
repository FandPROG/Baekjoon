#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int par[200010];

struct xyz
{
	int x, y, z;
};

bool comp(xyz a, xyz b)
{
	return a.z < b.z;
}

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
	while (1) {
		int sum = 0;
		vector <xyz> vec;
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) return 0;
		for (i = 0; i < m; i++) {
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			vec.push_back({ x, y, z });
			sum += z;
		}
		int ans = 0;
		sort(vec.begin(), vec.end(), comp);
		for (i = 1; i <= n; i++) par[i] = i;
		for (i = 0; i < m; i++) {
			if (ffind(vec[i].x) == ffind(vec[i].y)) continue;
			else {
				funion(vec[i].x, vec[i].y);
				ans += vec[i].z;
			}
		}
		printf("%d\n", sum - ans);
	}
	return 0;
}