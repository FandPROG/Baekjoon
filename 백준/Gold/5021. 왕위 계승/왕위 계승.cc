#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>

using namespace std;

int n, m;
string king;
map <string, vector<string>> vec;
map <string, double> ans;
map <string, int> ent;
set <string> st;
vector <string> s;

int main()
{
	int i, j;
	cin >> n >> m;
	cin >> king;
	ans.insert({ king, 1 });
	st.insert(king);
	ent.insert({ king, 0 });
	s.push_back(king);
	for (i = 1; i <= n; i++) {
		string x, y, z;
		cin >> x >> y >> z;
		if (st.find(x) == st.end()) {
			st.insert(x);
			ent.insert({ x, 0 });
			ans.insert({ x, 0 });
			s.push_back(x);
		}
		if (st.find(y) == st.end()) {
			st.insert(y);
			ent.insert({ y, 0 });
			ans.insert({ y, 0 });
			s.push_back(y);
		}
		if (st.find(z) == st.end()) {
			st.insert(z);
			ent.insert({ z, 0 });
			ans.insert({ z, 0 });
			s.push_back(z);
		}
		vec[y].push_back(x);
		vec[z].push_back(x);
		ent[x] += 2;
	}
	queue <string> q;
	for (i = 0; i < s.size(); i++) {
		if (ent[s[i]] == 0) q.push(s[i]);
	}
	while (!q.empty()) {
		string now = q.front();
		q.pop();
		for (i = 0; i < vec[now].size(); i++) {
			string nw = vec[now][i];
			ent[nw]--;
			ans[nw] += ans[now];
			if (ent[nw] == 0) {
				ans[nw] /= 2;
				q.push(nw);
			}
		}
	}
	string res;
	double mx = -2e9;
	for (i = 0; i < m; i++) {
		string x;
		cin >> x;
		if (mx < ans[x]) {
			mx = ans[x];
			res = x;
		}
	}
	cout << res;
	return 0;
}