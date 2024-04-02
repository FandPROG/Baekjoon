#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <vector>

using namespace std;

int v, e;
int node = 1, d[10010], ch[10010];
vector <int> vec[10010];
vector <pair<int, vector<int>>> scc;
stack <int> st;

int sccDFS(int x)
{
	int i, j;
	d[x] = node++;
	st.push(x);
	int par = d[x];
	for (i = 0; i < vec[x].size(); i++) {
		int nw = vec[x][i];
		if (d[nw] == 0) par = min(par, sccDFS(nw));
		else if (ch[nw] == 0) par = min(par, d[nw]);
	}
	if (par == d[x]) {
		vector <int> vc;
		int t = -2e9;
		while (t != x) {
			t = st.top();
			st.pop();
			vc.push_back(t);
			ch[t] = 1;
		}
		scc.push_back({ 0, vc });
		vc.clear();
	}
	return par;
}

int main()
{
	int i, j;
	scanf("%d %d", &v, &e);
	for (i = 0; i < e; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		vec[x].push_back(y);
	}
	for (i = 1; i <= v; i++) {
		if (d[i] == 0) sccDFS(i);
	}
	printf("%d\n", scc.size());
	for (i = 0; i < scc.size(); i++) {
		sort(scc[i].second.begin(), scc[i].second.end());
		scc[i].first = scc[i].second[0];
	}
	sort(scc.begin(), scc.end());
	for (i = 0; i < scc.size(); i++) {
		for (j = 0; j < scc[i].second.size(); j++) {
			printf("%d ", scc[i].second[j]);
		}
		printf("-1\n");
	}
	return 0;
}