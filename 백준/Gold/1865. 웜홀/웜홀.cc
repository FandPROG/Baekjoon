#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m, w;
int dis[510], ch[510];

struct dat {
	int x, y, val;
};

int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int i, j;
		vector <dat> vec;
		scanf("%d %d %d", &n, &m, &w);
		for (i = 0; i < m; i++) {
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			vec.push_back({ x, y, z });
			vec.push_back({ y, x, z });
		}
		for (i = 0; i < w; i++) {
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			vec.push_back({ x, y, -z });
		}
		for (i = 1; i <= n; i++) dis[i] = 2e9;
		for (i = 1; i <= n; i++) {
			if(dis[i] == 2e9) dis[i] = 0;
			for (j = 0; j < vec.size(); j++) {
				int x = vec[j].x, y = vec[j].y, val = vec[j].val;
				if (dis[x] == 2e9) continue;
				if (dis[y] > dis[x] + val) dis[y] = dis[x] + val;
			}
		}
		int ans = 1;
		for (i = 0; i < vec.size(); i++) {
			int x = vec[i].x, y = vec[i].y, val = vec[i].val;
			if (dis[x] == 2e9) continue;
			if (dis[y] > dis[x] + val) {
				ans = 0;
				break;
			}
		}
		if (ans == 1) printf("NO\n");
		else printf("YES\n");
		vec.clear();
	}
}