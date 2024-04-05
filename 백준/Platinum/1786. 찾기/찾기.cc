#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <int> ans;

vector <int> makeTable(string pat) {
	int i;
	int sz = pat.size();
	vector <int> table(sz, 0);
	int j = 0;
	for (i = 1; i < sz; i++) {
		while (j > 0 && pat[i] != pat[j]) {
			j = table[j - 1];
		}
		if (pat[i] == pat[j]) {
			table[i] = ++j;
		}
	}
	return table;
}

void KMP(string par, string pat) {
	vector <int> table = makeTable(pat);
	int par_sz = par.size(), pat_sz = pat.size();
	int i, j = 0;
	for (i = 0; i < par_sz; i++) {
		while (j > 0 && par[i] != pat[j]) {
			j = table[j - 1];
		}
		if (par[i] == pat[j]) {
			if (j == pat_sz - 1) {
				ans.push_back(i - pat_sz + 2);
				j = table[j];
			}
			else {
				j++;
			}
		}
	}
}

int main()
{
	int i, j;
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	KMP(s1, s2);
	cout << ans.size() << '\n';
	for (i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}