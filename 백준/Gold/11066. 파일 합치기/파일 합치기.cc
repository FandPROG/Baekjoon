#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[510][510];
int arr[510];
int sum[510];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        int i, j;
        int k;
        scanf("%d", &k);
        for(i=1;i<=k;i++) {
            scanf("%d", &arr[i]);
            sum[i] = sum[i - 1] + arr[i];
        }
        for(i=1;i<=k;i++) {
            for(j=1;j<=k;j++) {
                if(i == j) continue;
                dp[i][j] = 2e9;
            }
        }
        for(i=1;i<k;i++) {
            for(j=1;i + j <= k;j++) {
                int s = j;
                int e = i + j;
                for(int m = s;m<e;m++) {
                    dp[s][e] = min(dp[s][e], dp[s][m] + dp[m + 1][e] + sum[e] - sum[s - 1]);
                }
            }
        }
        printf("%d\n", dp[1][k]);
    }    
    return 0;
}