#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int d[100010], n, m, node;
int idx[100010], ch[100010];
int ent[100010];

vector <int> vec[100010];
vector <vector<int>> scc;
stack <int> st;

int sccfind(int x)
{
	int i, j;
	d[x] = node++;
	int par = d[x];
	st.push(x);
	for (i = 0; i < vec[x].size(); i++) {
		int nw = vec[x][i];
		if (d[nw] == 0) par = min(par, sccfind(nw));
		else if (ch[nw] == 0) par = min(d[nw], par);
	}
	if (d[x] == par) {
		vector <int> vc;
		int nod = scc.size();
		while (1) {
			int t = st.top();
			st.pop();
			ch[t] = 1;
			idx[t] = nod;
			vc.push_back(t);
			if (t == x) break;
		}
		scc.push_back(vc);
	}
	return par;
}

int main()
{
	int i, j;
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (i = 0; i < m; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			vec[x].push_back(y);
		}
		node = 1;
		for (i = 0; i < n; i++) {
			if (d[i] == 0) sccfind(i);
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < vec[i].size(); j++) {
				int nw = vec[i][j];
				if (idx[i] != idx[nw]) {
					ent[idx[nw]]++;
				}
			}
		}
		int ans = 0;
		int ans_idx;
		for (i = 0; i < scc.size(); i++) {
			if (ent[i] == 0) ans++, ans_idx = i;
		}
		if (ans == 1) {
			sort(scc[ans_idx].begin(), scc[ans_idx].end());
			for (i = 0; i < scc[ans_idx].size(); i++) {
				printf("%d\n", scc[ans_idx][i]);
			}
		}
		else printf("Confused\n");
		for (i = 0; i < n; i++) ch[i] = 0, ent[i] = 0, idx[i] = 0, d[i] = 0, vec[i].clear();
		while (!st.empty()) st.pop();
		scc.clear();
		printf("\n");
	}
}