#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int i, j;
    int n;
    scanf("%d", &n);
    vector <int> vec(n), dp(n);
    for(i=0;i<n;i++) scanf("%d", &vec[i]);
    dp[0] = 1;
    for(i=1;i<n;i++) {
        if(dp[i - 1] + 1 > vec[i]) dp[i] = vec[i];
        else dp[i] = dp[i - 1] + 1;
    }
    int ans = 0;
    for(i=0;i<n;i++) ans = max(ans, dp[i]);
    printf("%d", ans);
    return 0;
}