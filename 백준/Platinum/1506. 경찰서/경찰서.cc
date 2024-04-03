#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int n, node = 1;
int cost[110];
int d[110], ch[110];
vector <vector<int>> scc;
vector <int> vec[110];
stack <int> st;

int sccdfs(int x)
{
	int i, j;
	d[x] = node++;
	st.push(x);
	int par = d[x];
	for (i = 0; i < vec[x].size(); i++) {
		int nw = vec[x][i];
		if (d[nw] == 0) par = min(par, sccdfs(nw));
		else if (ch[nw] == 0) par = min(par, d[nw]);
	}
	if (d[x] == par) {
		vector <int> vc;
		while (1) {
			int t = st.top();
			st.pop();
			vc.push_back(t);
			ch[t] = 1;
			if (t == x) break;
		}
		scc.push_back(vc);
	}
	return par;
}

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &cost[i]);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			int x;
			scanf("%1d", &x);
			if (x == 1) vec[i].push_back(j);
		}
	}
	for (i = 1; i <= n; i++) {
		if (d[i] == 0) sccdfs(i);
	}
	int ans = 0;
	for (i = 0; i < scc.size(); i++) {
		int mn = 2e9;
		for (j = 0; j < scc[i].size(); j++) {
			mn = min(cost[scc[i][j]], mn);
		}
		ans += mn;
	}
	printf("%d", ans);
	return 0;
}