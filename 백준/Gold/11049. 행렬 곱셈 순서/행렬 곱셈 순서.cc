#include <stdio.h>

int dp[510][510], a[2][510], min = 99999999;

int main()
{
	int i, j, k, b, c;
	scanf("%d", &b);
	for(i=0;i<b;i++) scanf("%d %d", &a[0][i], &a[1][i]);
	for(k=1;k<b;k++) {
		for(i=0;i+k<b;i++) {
			for(j=i;j<i+k;j++) {
				c = dp[i][j] + dp[j+1][k+i] + a[0][i]*a[1][j]*a[1][k+i];
				if(c < min) min = c;
			}
			dp[i][i+k] = min;
			min = 999999999;
		}
	}
	printf("%d", dp[0][b-1]);
	return 0;
} 
