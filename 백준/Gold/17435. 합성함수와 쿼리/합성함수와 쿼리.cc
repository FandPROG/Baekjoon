#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int dp[200010][19];

int main()
{
    int i, j;
    int n;
    scanf("%d", &n);
    for(i=1;i<=n;i++) scanf("%d", &dp[i][0]);
    for(i=1;i<=18;i++) {
        for(j=1;j<=n;j++) {
            dp[j][i] = dp[dp[j][i-1]][i - 1];
        }
    }
    int Q;
    scanf("%d", &Q);
    while(Q--) {
        int m, x;
        scanf("%d %d", &m, &x);
        for(i=0;i<=18;i++) {
            if((m & (1 << i)) != 0) {
                x = dp[x][i];
            }
        }
        printf("%d\n", x);
    }
    return 0;
}