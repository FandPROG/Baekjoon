#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int dp[100010][31];

int main()
{
    int i, j;
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);
    vector <int> query(n);
    for(i=0;i<n;i++) scanf("%d", &query[i]);
    for(i=1;i<=k;i++) scanf("%d", &dp[i][0]);
    for(i=1;i<=30;i++) {
        for(j=1;j<=k;j++) {
            dp[j][i] = dp[dp[j][i - 1]][i - 1];
        }
    }
    vector <int> ans;
    for(int Q : query) {
        int x = Q;
        for(i=0;i<=30;i++) {
            if(((m - 1) & (1<<i)) != 0) {
                x = dp[x][i];
            }
        }
        ans.push_back(x);
    }
    for(int res : ans) {
        printf("%d ", res);
    }
    return 0;
}