#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

int n, m;
set <string> st;
map <string, int> mp;
string ch1[5] = { "kor", "eng", "math" };
string ch2[5] = { "apple", "pear", "orange" };
string ch3[5] = { "red", "blue", "green" };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int i, j;
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		string s1, s2, s3;
		cin >> s1 >> s2 >> s3;
		st.insert(s1 + s2 + s3);
		if (st.find(s1 + s2 + s3) != st.end()) mp[s1 + s2 + s3]++;
		mp.insert({ s1 + s2 + s3, 0 });
	}
	for (i = 0; i < m; i++) {
		string s1, s2, s3;
		int cnt = 0;
		cin >> s1 >> s2 >> s3;
		if (s1 == "-" && s2 == "-" && s3 == "-") {
			cout << n << '\n';
			continue;
		}
		else if (s1 == "-" && s2 == "-") {
			for (j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					string fin = ch1[j] + ch2[k] + s3;
					if (st.find(fin) != st.end()) cnt += mp[fin];
				}
			}
		}
		else if (s2 == "-" && s3 == "-") {
			for (j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					string fin = s1 + ch2[j] + ch3[k];
					if (st.find(fin) != st.end()) cnt += mp[fin];
				}
			}
		}
		else if (s3 == "-" && s1 == "-") {
			for (j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					string fin = ch1[k] + s2 + ch3[j];
					if (st.find(fin) != st.end()) cnt += mp[fin];
				}
			}
		}
		else if (s1 == "-") {
			for (j = 0; j < 3; j++) {
				string fin = ch1[j] + s2 + s3;
				if (st.find(fin) != st.end()) cnt += mp[fin];
			}
		}
		else if (s2 == "-") {
			for (j = 0; j < 3; j++) {
				string fin = s1 + ch2[j] + s3;
				if (st.find(fin) != st.end()) cnt += mp[fin];
			}
		}
		else if (s3 == "-") {
			for (j = 0; j < 3; j++) {
				string fin = s1 + s2 + ch3[j];
				if (st.find(fin) != st.end()) cnt += mp[fin];
			}
		}
		else {
			string fin = s1 + s2 + s3;
			if (st.find(fin) != st.end()) cnt += mp[fin];
		}
		cout << cnt << '\n';
	}
	return 0;
}