#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char s1[4010], s2[4010];
int n1, n2;
int dp[4010][4010];
int ans = 0;

int main()
{
	int i, j;
	scanf("%s", s1 + 1);
	scanf("%s", s2 + 1);
	s1[0] = '0', s2[0] = '0';
	n1 = strlen(s1) - 1;
	n2 = strlen(s2) - 1;
	for (i = 1; i <= n1; i++) {
		for (j = 1; j <= n2; j++) {
			if (s1[i] == s2[j]) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
				if (dp[i][j] > ans) ans = dp[i][j];
			}
		}
	}
	printf("%d", ans);
	return 0;
}