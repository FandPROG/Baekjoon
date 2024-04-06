#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

int n;
set <string> st;
vector <string> ans;
int main()
{
	int i, j;
	cin >> n;
	for (i = 0; i < n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		if (s2 == "enter") st.insert(s1);
		if (s2 == "leave") st.erase(s1);
	}
	for (auto itr = st.begin(); itr != st.end(); itr++) ans.push_back(*itr);
	for (i = ans.size() - 1; i >= 0; i--) cout << ans[i] << '\n';
	return 0;
}