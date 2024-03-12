#include <stdio.h>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int dp[1000010][20];
vector <int> vec;

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0;; i++) {
		int x = pow(2, i);
		if (n < x) break;
		vec.push_back(x);
	}
	for (i = 0; i < vec.size(); i++) {
		dp[vec[i]][i] = 1;
		for (j = 1; j <= n; j++) {
			if(i > 0) dp[j][i] = (dp[j][i] + dp[j][i - 1]) % 1000000000;
			if (j >= vec[i]) dp[j][i] = (dp[j][i] + dp[j - vec[i]][i]) % 1000000000;
		}
	}
	printf("%d", dp[n][vec.size() - 1]);
	return 0;
}