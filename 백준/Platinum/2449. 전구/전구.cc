#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[210][210], arr, r, l, ar[210];

int main()
{
	int n, k, i, j;
	scanf("%d %d", &n, &k);
	for(i=1;i<=n;i++) {
		scanf("%d", &arr);
		if(r == arr);
		else {
			ar[++l] = arr;
			r = arr;
		}
	}
	for(i=1;i<=l;i++) dp[i][i+1] = 1;
	for(i=2;i<l;i++) {
		for(j=1;j+i<=l;j++) {
			dp[j][j+i] = 2e9;
			if(ar[j] == ar[j+i]) {
				dp[j][j+i] = min(dp[j][j+i], dp[j+1][j+i-1]+1);
			}  
			for(k=j+1;k<j+i;k++) {
				dp[j][j+i] = min(dp[j][j+i], dp[j][k]+dp[k][j+i]);
			}
		}
	}
	printf("%d", dp[1][l]);
	return 0;
}