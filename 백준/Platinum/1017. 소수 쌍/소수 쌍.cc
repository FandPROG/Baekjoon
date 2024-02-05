#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int pr[2020], par[2020], ch[2020];
vector<int> ans, a, b;
vector<int> g[2020];
int bias = 50;

bool che = 0;

int fa, fb;

void era()
{
	int i, j;
	for (i = 2; i < 2020; i++) pr[i] = 1;
	for (i = 1; i < 2020; i++) {
		if (!pr[i]) continue;
		for (j = i + i; j < 2020; j += i) pr[j] = 0;
	}
}

bool dfs(int v)
{
	int i, j;
	for (i = 0; i < g[v].size(); i++) {
		if (ch[g[v][i]]) continue;
		if (g[v][i] == fa || g[v][i] == fb) continue;
		ch[g[v][i]] = 1;
		if (!pr[a[v] + b[g[v][i] - bias]]) continue;
		if (par[g[v][i]] == -1 || dfs(par[g[v][i]])) {
			par[g[v][i]] = v;
			return 1;
		}
	}
	return 0;
}

int main()
{
	int i, j;
	era();
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		int t;
		scanf("%d", &t);
		if (i == 1 && t % 2 == 0) che = 1;
		if (t % 2 == 1) a.push_back(t);
		else b.push_back(t);
	}
	if (a.size() != b.size()) {
		printf("-1");
		return 0;
	}
	if (che) swap(a, b);
	for (i = 0; i < a.size(); i++) {
		for (j = 0; j < b.size(); j++) {
			if (pr[a[i] + b[j]]) g[i].push_back(j + bias);
		}
	}

	for (i = 0; i < b.size(); i++) {
		fill(par, par + 2020, -1);
		if (!pr[a[0] + b[i]]) continue;
		int match = 1;
		par[i + bias] = 0;
		fa = 0, fb = i + bias;

		for (j = 1; j < a.size(); j++) {
			fill(ch, ch + 2020, 0);
			ch[0] = ch[i + bias] = 1;
			match += dfs(j);
		}

		if (match != b.size()) continue;
		ans.push_back(b[i]);
	}
	if (ans.size()) {
		sort(ans.begin(), ans.end());
		for (i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
	}
	else printf("-1");
	return 0;
}