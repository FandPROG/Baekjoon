#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int deep[100010];
int n, s, d, ans;
vector <int> vec[100010];
int che[100010], ch[100010];

int dfs1(int x) {
	int i, dep = 0;
	for (i = 0; i < vec[x].size(); i++) {
		int now = vec[x][i];
		if (che[now] == 1) continue;
		che[now] = 1;
		dep = dfs1(now);
		deep[x] = max(deep[x], dep);
	}
	return max(deep[x], dep) + 1;
}

void dfs(int x)
{
	int i, j;
	for (i = 0; i < vec[x].size(); i++) {
		int now = vec[x][i];
		if (ch[now] == 0 && deep[now] >= d) {
			ch[now] = 1;
			ans++;
			dfs(now);
		}
	}
	return;
}

int main()
{
	int i, j;
	scanf("%d %d %d", &n, &s, &d);
	for (i = 0; i < n - 1; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	che[s] = 1;
	dfs1(s);
	ch[s] = 1;
	dfs(s);
	printf("%d", ans * 2);
	return 0;
}