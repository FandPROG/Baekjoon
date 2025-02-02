#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using lD = long double;
using D = double;

int n, m, k;
int dp[310][310]; //현재 (x, y)에 말이 있고, 내가 움직여야할때, 내가 이기면 2, 지면 1
char mp[310][310];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, j;
    cin >> n >> m >> k;
    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            cin >> mp[i][j];
        }
    }
    dp[n][m] = 1;
    for(i=n;i>=1;i--) {
        for(j=m;j>=1;j--) {
            if(mp[i][j] == '#') continue;
            bool IsNotExist = false;
            for(int a=1;a<=k;a++) {
                if(a + i > n || a + j > m) break;
                if(mp[a + i][a + j] == '#') continue;
                if(dp[a + i][a + j] == 2) IsNotExist = true;
                if(dp[a + i][a + j] == 1) dp[i][j] = 2;
            }
            if(i + 1 <= n && mp[i + 1][j] == '.') {
                dp[i][j] = (dp[i + 1][j] == 1 ? 2 : dp[i][j]);
                if(dp[i + 1][j] == 2) IsNotExist = true;
            }
            if(j + 1 <= m && mp[i][j + 1] == '.') {
                dp[i][j] = (dp[i][j + 1] == 1 ? 2 : dp[i][j]);
                if(dp[i][j + 1] == 2) IsNotExist = true;
            }
            if(dp[i][j] == 0 && IsNotExist) dp[i][j] = 1;
        }
    }
    int Q;
    cin >> Q;
    while(Q--) {
        int x, y;
        cin >> x >> y;
        if(dp[x][y] == 2) cout << "First" << "\n";
        else cout << "Second" << "\n";
    }
    return 0;
}