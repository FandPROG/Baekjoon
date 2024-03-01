#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int dp[100010], n;
vector <int> vec;

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 1;; i++) {
		if (i * i > n) break;
		vec.push_back(i * i);
	}
	for (i = 1; i <= n; i++) dp[i] = 2e9;
	for (i = 1; i <= n; i++) {
		for (j = 0; j < vec.size(); j++) {
			if (i >= vec[j]) dp[i] = min(dp[i], dp[i - vec[j]] + 1);
		}
	}
	printf("%d", dp[n]);
	return 0;
}