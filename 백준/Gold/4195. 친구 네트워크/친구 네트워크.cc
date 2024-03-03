#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int par[200010];
vector <pair<string, string>> vec;
int cnt[200010];

int ffind(int x)
{
	if (par[x] == x) return x;
	else return par[x] = ffind(par[x]);
}

void funion(int x, int y)
{
	int a = ffind(x);
	int b = ffind(y);
	if (a == b) return;
	else {
		par[b] = a;
		cnt[a] += cnt[b];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int idx = 1;
		int n;
		cin >> n;
		set <string> st;
		map <string, int> mp;
		for (int i = 0; i < n; i++) {
			string s1, s2;
			cin >> s1 >> s2;
			if (st.find(s1) == st.end()) st.insert(s1), mp.insert({ s1, idx++ });
			if (st.find(s2) == st.end()) st.insert(s2), mp.insert({ s2, idx++ });
			vec.push_back({ s1, s2 });
		}
		for (int i = 1; i <= idx; i++) par[i] = i, cnt[i] = 1;
		for (int i = 0; i < vec.size(); i++) {
			funion(mp[vec[i].first], mp[vec[i].second]);
			int x = ffind(mp[vec[i].first]);
			cout << cnt[x] << '\n';
		}
		vec.clear();
		mp.clear();
		st.clear();
	}
	return 0;
}