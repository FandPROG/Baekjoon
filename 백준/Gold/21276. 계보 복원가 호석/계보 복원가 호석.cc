#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int n, k;
map <string, int> ent;
map <string, vector<string>> sea, mp, ans;
string s[1010], root[1010];
int root_cnt;
queue <string> q;

int main()
{
	int i, j;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> s[i];
		ent.insert({ s[i], 0 });

	}
	cin >> k;
	for (i = 0; i < k; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		ent[s1]++;
		mp[s2].push_back(s1);
		sea[s1].push_back(s2);
	}
	for (i = 1; i <= n; i++) {
		if (sea[s[i]].size() == 0) root[root_cnt++] = s[i];
		if (ent[s[i]] == 0) q.push(s[i]);
	}
	while (!q.empty()) {
		string now = q.front();
		q.pop();
		for (i = 0; i < mp[now].size(); i++) {
			string nw = mp[now][i];
			ent[nw]--;
			if (ent[nw] == 0) {
				q.push(nw);
				ans[now].push_back(nw);
			}
		}
	}
	sort(root, root + root_cnt);
	sort(s + 1, s + n + 1);
	cout << root_cnt << '\n';
	for (i = 0; i < root_cnt; i++) cout << root[i] << ' ';
	cout << '\n';
	for (i = 1; i <= n; i++) {
		cout << s[i] << ' ' << ans[s[i]].size() << ' ';
		for (j = 0; j < ans[s[i]].size(); j++) cout << ans[s[i]][j] << ' ';
		cout << '\n';
	}
	return 0;
}