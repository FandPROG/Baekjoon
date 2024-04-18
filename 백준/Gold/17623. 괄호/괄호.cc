#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cmath>

using namespace std;

string dp[1010];
map <char, int> mp;

unsigned long long Sres(string s)
{
	int i, j = s.size() - 1;
	unsigned long long res = 0;
	for (i = 0; i < s.size(); i++, j--) {
		res += mp[s[i]] * pow(10, j);
	}
	return res;
}

int main()
{
	int i, j;
	int t;
	cin >> t;
	dp[1] = "()";
	dp[2] = "{}";
	dp[3] = "[]";
	mp.insert({ '(', 1 });
	mp.insert({ ')', 2 });
	mp.insert({ '{', 3 });
	mp.insert({ '}', 4 });
	mp.insert({ '[', 5 });
	mp.insert({ ']', 6 });
	for (i = 4; i <= 1000; i++) {
		unsigned long long imsi;
		dp[i] = "()" + dp[i - 1];

		if (i % 2 == 0) {
			imsi = Sres("(" + dp[i / 2] + ")");
			if (imsi < Sres(dp[i])) dp[i] = "(" + dp[i / 2] + ")";
		}

		if (i % 3 == 0) {
			imsi = Sres("{" + dp[i / 3] + "}");
			if (imsi < Sres(dp[i])) dp[i] = "{" + dp[i / 3] + "}";
		}

		if (i % 5 == 0) {
			imsi = Sres("[" + dp[i / 5] + "]");
			if (imsi < Sres(dp[i])) dp[i] = "[" + dp[i / 5] + "]";
		}

		imsi = Sres(dp[i - 1] + "()");
		if (imsi < Sres(dp[i])) dp[i] = dp[i - 1] + "()";

		imsi = Sres(dp[i - 2] + "{}");
		if (imsi < Sres(dp[i])) dp[i] = dp[i - 2] + "{}";

		imsi = Sres("{}" + dp[i - 2]);
		if (imsi < Sres(dp[i])) dp[i] = "{}" + dp[i - 2];

		imsi = Sres(dp[i - 3] + "[]");
		if (imsi < Sres(dp[i])) dp[i] = dp[i - 3] + "[]";

		imsi = Sres("[]" + dp[i - 3]);
		if (imsi < Sres(dp[i])) dp[i] = "[]" + dp[i - 3];
	}
	while (t--) {
		int x;
		cin >> x;
		cout << dp[x] << '\n';
	}
	return 0;
}