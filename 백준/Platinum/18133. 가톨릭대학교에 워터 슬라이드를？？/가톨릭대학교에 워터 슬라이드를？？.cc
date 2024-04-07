#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int n, m, node = 1;
int id[100010], idx[100010];
int ent[100010];
vector <int> vec[100010];
vector <vector<int>> scc;
stack <int> st;

int make_scc(int x)
{
	int i, j;
	id[x] = node++;
	st.push(x);
	int par = id[x];
	for (i = 0; i < vec[x].size(); i++) {
		int nw = vec[x][i];
		if (id[nw] == 0) par = min(par, make_scc(nw));
		else if (idx[nw] == 0) par = min(par, id[nw]);
	}
	if (id[x] == par) {
		vector <int> vc;
		int ix = scc.size() + 1;
		while (1) {
			int t = st.top();
			st.pop();
			vc.push_back(t);
			idx[t] = ix;
			if (t == x) break;
		}
		scc.push_back(vc);
	}
	return par;
}

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		vec[x].push_back(y);
	}
	for (i = 1; i <= n; i++) {
		if (id[i] == 0) make_scc(i);
	}
	for (i = 1; i <= n; i++) {
		for (j = 0; j < vec[i].size(); j++) {
			int nw = vec[i][j];
			if (idx[i] != idx[nw]) ent[idx[nw]]++;
		}
	}
	int ans = 0;
	for (i = 1; i <= scc.size(); i++) {
		if (ent[i] == 0) ans++;
	}
	printf("%d", ans);
	return 0;
}