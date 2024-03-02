#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int dp[30][10010];

int main()
{
	int i, j;
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		vector <int> vec;
		for (i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			vec.push_back(x);
		}
		int m;
		scanf("%d", &m);
		for (i = 0; i < n; i++) {
			for (j = 1; j <= m; j++) {
				dp[i][j] = 0;
			}
		}
		for (i = 0; i < n; i++) {
			dp[i][vec[i]] = 1;
			for (j = 1; j <= m; j++) {
				if (i > 0) dp[i][j] += dp[i - 1][j];
				if (j >= vec[i]) dp[i][j] += dp[i][j - vec[i]];
			}
		}
		/*for (i = 0; i < n; i++) {
			for (j = 1; j <= m; j++) {
				printf("%d ", dp[i][j]);
			}
			printf("\n");
		}*/
		printf("%d\n", dp[n - 1][m]);
	}
	return 0;
}