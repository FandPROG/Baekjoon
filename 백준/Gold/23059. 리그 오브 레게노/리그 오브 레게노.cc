#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

int n, m, cnt, ent[400010], ch[400010];
string king;
unordered_map <string, int> mp;
set <string> st;
vector <string> s, ans[400010];
vector <int> vec[400010];

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int i, j;
	cin >> n;
	for (i = 1; i <= n; i++) {
		string x, y;
		cin >> x >> y;
		if (st.find(x) == st.end()) {
			st.insert(x);
			mp.insert({ x, cnt++ });
			s.push_back(x);
		}
		if (st.find(y) == st.end()) {
			st.insert(y);
			mp.insert({ y, cnt++ });
			s.push_back(y);
		}
		vec[mp[x]].push_back(mp[y]);
		ent[mp[y]]++;
	}
	queue <pair<int, int>> q;
	for (i = 0; i < s.size(); i++) {
		if (ent[mp[s[i]]] == 0) {
			q.push({ mp[s[i]], 0 });
		}
	}
	int maaax = -2e9;
	while (!q.empty()) {
		int now = q.front().first, nval = q.front().second;
		q.pop();
		ch[now] = 1;
		ans[nval].push_back(s[now]);
		for (i = 0; i < vec[now].size(); i++) {
			int nw = vec[now][i];
			ent[nw]--;
			if (ent[nw] == 0) {
				maaax = max(maaax, nval + 1);
				q.push({ nw, nval + 1 });
			}
		}
	}
	int check = 0;
	for (i = 0; i < s.size(); i++) {
		if (ch[i] == 0) check = 1;
	}
	if (check == 1) cout << "-1";

	else {
		for (i = 0; i <= maaax; i++) {
			sort(ans[i].begin(), ans[i].end());
			for (j = 0; j < ans[i].size(); j++) cout << ans[i][j] << '\n';
		}
	}
	return 0;
}