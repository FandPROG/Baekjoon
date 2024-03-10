#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

unsigned long long dp[210][110];
unsigned long long n, m, k;
unsigned long long nx, ny;
vector <char> vec;

int main()
{
	unsigned long long i, j;
	scanf("%llu %llu %llu", &n, &m, &k);
	nx = n;
	ny = m;
	dp[0][0] = 1;
	for (i = 1; i <= n + m; i++) {
		for (j = 0; j <= m; j++) {
			if (j > 0) dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]);
			else dp[i][j] = 1;
		}
	}
	if (dp[n + m][m] < k) {
		printf("-1");
		return 0;
	}
	unsigned long long now = k;
	for (i = 0; i < n + m; i++) {
		unsigned long long now_com = dp[nx - 1 + ny][ny];
		if (now_com >= now) {
			nx--;
			vec.push_back('a');
		}
		else {
			ny--;
			vec.push_back('z');
			now -= now_com;
		}
	}
	for (i = 0; i < vec.size(); i++) printf("%c", vec[i]);
	return 0;
}