#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;

int main()
{
    int n, k;
    cin >> n >> k;
    vector <vector<int>> dp(k + 1, vector<int>(n + 1));
    vector <int> vec(n + 1);
    for(int i=1;i<=n;i++) cin >> vec[i];
    for(int i=1;i<=n;i++) dp[1][i] = i;
    for(int i=2;i<=k;i++) {
        for(int j=i;j<=n;j++) {
            dp[i][j] = (dp[i][j - 1] + ((dp[i - 1][j - 1] * 2)  % MOD)) % MOD;
        }
    }
    cout << dp[k][n] % MOD;
    return 0;
}
