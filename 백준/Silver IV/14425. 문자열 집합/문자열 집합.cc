#include <set>
#include <string>
#include <iostream>

using namespace std;

int n, m;
set <string> st;

int main()
{
	int i, j;
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		string s;
		cin >> s;
		st.insert(s);
	}
	int cnt = 0;
	for (i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (st.find(s) == st.end());
		else cnt++;
	}
	cout << cnt << endl;
	return 0;
}