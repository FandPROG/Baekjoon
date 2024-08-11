#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int dp[510][510];
int sum[510];

int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int i, j, n;
		vector <int> vec;
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			vec.push_back(x);
		}
		sum[0] = vec[0];
		for (i = 1; i < n; i++) sum[i] = sum[i - 1] + vec[i];
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				dp[i][j] = 2e9;
			}
		}
		for (i = 0; i < n; i++) dp[i][i] = 0;
		for (i = 1; i < n; i++) {
			for (j = 0; i + j < n; j++) {
				int s = j;
				int e = i + j;
				for (int k = s; k < e; k++) {
					int ssm;
					if (s == 0) ssm = 0;
					else ssm = sum[s - 1];
					dp[s][e] = min(dp[s][e], dp[s][k] + dp[k + 1][e] + sum[e] - ssm);
				}
			}
		}
		printf("%d\n", dp[0][n - 1]);
	}
}