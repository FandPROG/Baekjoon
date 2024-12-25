#include <stdio.h>
#include <algorithm>

using namespace std;
using ll = long long;

int n;
ll k;
ll A[200010];
ll B[200010];
ll dp[2][200010];

int main()
{
    int i, j;
    scanf("%d %lld", &n, &k);
    for(i=0;i<n;i++) scanf("%lld", &A[i]);
    for(i=0;i<n;i++) scanf("%lld", &B[i]);
    dp[0][0] = A[0];
    dp[1][0] = B[0];
    for(i=1;i<n;i++) {
        dp[0][i] = min(dp[0][i - 1] + A[i], dp[1][i - 1] + A[i] + k);
        dp[1][i] = min(dp[1][i - 1] + B[i], dp[0][i - 1] + B[i] + k);
    }
    printf("%lld", min(dp[0][n - 1], dp[1][n - 1]));
    return 0;
}