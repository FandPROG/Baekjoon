#include <stdio.h>
#include <algorithm>

using namespace std;

int fdp[100010];
int edp[100010];
int dp[100010];
int Tsize[100010];
int N;

int MOD = 1000000007;

int main()
{
    dp[0] = 1;
    fdp[0] = 1;
    edp[0] = 1;
    Tsize[0] = 1;
    scanf("%d", &N);
    for(int i=1;i<=N;i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        int n = i;
        Tsize[n] = (Tsize[x] + Tsize[y]) % MOD;
        fdp[n] = (fdp[x] + ((fdp[y] + Tsize[y]) % MOD) - 1) % MOD;
        edp[n] = (edp[y] + ((edp[x] + Tsize[x]) % MOD) - 1) % MOD;
        dp[n] = ((((dp[x] + dp[y]) % MOD) + ((Tsize[y] * edp[x]) % MOD)) % MOD + ((Tsize[x] * fdp[y]) % MOD)) % MOD - 1;
    }
    for(int i=1;i<=N;i++) printf("%d\n", dp[i] % MOD);
    return 0;
}