#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using lD = long double;
using D = double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, j;
    int n;
    cin >> n;
    vector <int> dp(n + 1);
    fill(dp.begin(), dp.end(), 2e9);
    int coin[4] = {1, 2, 5, 7};
    dp[0] = 0;
    dp[1] = 1;
    for(i=0;i<4;i++) {
        for(j=coin[i];j<=n;j++) {
            dp[j] = min(dp[j], dp[j - coin[i]] + 1);
        }
    }
    cout << dp[n];
    return 0;
}