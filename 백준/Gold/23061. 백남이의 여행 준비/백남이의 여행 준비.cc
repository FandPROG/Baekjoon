#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int dp[110][1000010];
vector <pair<int, int>> vec;
vector <int> bag;

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	vec.push_back({ 0, 0 });
	for (i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		vec.push_back({ x, y });
	}
	int mx = -2e9;
	for (i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		bag.push_back(x);
		if (mx < x) mx = x;
	}
	for (i = 1; i < vec.size(); i++) {
		for (j = 0; j <= mx; j++) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			if (j >= vec[i].first) dp[i][j] = max(dp[i][j], dp[i - 1][j - vec[i].first] + vec[i].second);
		}
	}
	int ans;
	double res = -2e9;
	for (i = 0; i < bag.size(); i++) {
		double x = (double)dp[n][bag[i]] / (double)bag[i];
		//printf("%lf\n", x);
		if (x > res) {
			res = x;
			ans = i + 1;
		}
	}
	printf("%d", ans);
	return 0;
}