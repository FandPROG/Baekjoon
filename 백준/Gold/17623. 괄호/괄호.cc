#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
string dp[1010];
char d_s[15] = { ' ', '(', ')', '{', '}', '[', ']'};

string compare(string a, string b)
{
	if (a.size() == 0 || a.size() > b.size()) return b;
	if (b.size() > a.size()) return a;
	return min(a, b);
}

int main()
{
	int t, i, j;
	scanf("%d", &t);
	dp[1] = "12";
	dp[2] = "34";
	dp[3] = "56";
	for (i = 4; i <= 1000; i++) {
		if (i % 2 == 0) dp[i] = compare(dp[i], "1" + dp[i / 2] + "2");
		if (i % 3 == 0) dp[i] = compare(dp[i], "3" + dp[i / 3] + "4");
		if (i % 5 == 0) dp[i] = compare(dp[i], "5" + dp[i / 5] + "6");
		for (j = 1; j < i; j++) dp[i] = compare(dp[i], dp[j] + dp[i - j]);
	}
	while(t--) {
		scanf("%d", &n);
		for (i = 0; i < dp[n].size(); i++) printf("%c", d_s[dp[n][i] - '0']);
		printf("\n");

	}
	return 0;
}