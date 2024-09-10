#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

#define MOD 1000000009;
int dp[100010];

int main()
{
    int i, j;
    int t;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 2;
    dp[4] = 3;
    dp[5] = 3;
    dp[6] = 6;
    for(i=7;i<=100000;i++) {
        int res = (dp[i - 2] + dp[i - 4]) % MOD;
        res = (res + dp[i - 6]) % MOD;
        dp[i] = res;
    }
    scanf("%d", &t);
    while(t--) {
        int x;
        scanf("%d", &x);
        printf("%d\n", dp[x]);
    }
    return 0;
}
