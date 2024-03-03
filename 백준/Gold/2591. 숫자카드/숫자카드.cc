#include <stdio.h>
#include <string.h>

using namespace std;

char s[50];
int dp[50], x;

int main()
{
	int i, j;
	scanf("%s", s + 1);
	if (s[1] == '0') {
		printf("0");
		return 0;
	}
	s[0] = '0';
	x = strlen(s) - 1;
	dp[0] = 1;
	dp[1] = 1;
	for (i = 2; i <= x; i++) {
		int a = s[i - 1] - '0';
		int b = s[i] - '0';
		if (b > 0) dp[i] += dp[i - 1];
		if (a == 0) continue;
		if (a * 10 + b <= 34) dp[i] += dp[i - 2];
	}
	printf("%d", dp[x]);
	return 0;
}