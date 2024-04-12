#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int i, j;
	string s;
	set <string> st;
	cin >> s;
	int n = s.size();
	for (i = 0; i < n; i++) {
		string s1;
		for (j = i; j < n; j++) {
			s1 += s[j];
			st.insert(s1);
		}
	}
	cout << st.size();
	return 0;
}