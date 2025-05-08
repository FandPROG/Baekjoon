#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using lD = long double;
using D = double;

struct waydat {
    int x, y, damageType;
};

int n, a, l;
int dp[5010][5010];
waydat way[5010][5010];
string ans;

void backwayprint(int x, int y)
{
    if(way[x][y].damageType == 1) ans += "A";
    if(way[x][y].damageType == 2) ans += "L";
    if(x == 0 && y == l) return;
    else {
        backwayprint(way[x][y].x, way[x][y].y);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, j;
    cin >> n >> a >> l;
    vector <pair<int, int>> vec(n);
    for(i=0;i<n;i++) cin >> vec[i].first >> vec[i].second;
    for(i=0;i<=n;i++) {
        for(j=0;j<=l;j++) {
            dp[i][j] = -1;
        }
    }
    dp[0][l] = a;
    for(i=0;i<n;i++) {
        for(j=l;j>=0;j--) {
            if(dp[i][j] > -1) {
                if(vec[i].first == -1) {
                    if(j > vec[i].second) {
                        dp[i + 1][j - vec[i].second] = dp[i][j];
                        way[i + 1][j - vec[i].second] = {i, j, 2};
                    }
                    continue;
                }
                if(vec[i].second == -1) {
                    dp[i + 1][j] = max(0, dp[i][j] - vec[i].first);
                    way[i + 1][j] = {i, j, 1};
                    continue;
                }
                if(j > vec[i].second) {
                    if(dp[i + 1][j - vec[i].second] <= dp[i][j]) {
                        dp[i + 1][j - vec[i].second] = dp[i][j];
                        way[i + 1][j - vec[i].second] = {i, j, 2};
                    }
                }
                if(dp[i][j] >= vec[i].first) {
                    if(dp[i + 1][j] <= dp[i][j] - vec[i].first) {
                        dp[i + 1][j] = dp[i][j] - vec[i].first;
                        way[i + 1][j] = {i, j, 1};
                    }
                }
            }
        }
    }
    // for(i=0;i<=n;i++) {
    //     for(j=l;j>=0;j--) {
    //         printf("%d ", way[i][j].damageType);
    //     }
    //     printf("\n");
    // }
    for(i=l;i>0;i--) {
        if(dp[n][i] > -1) {
            cout << "YES" << endl;
            backwayprint(n, i);
            reverse(ans.begin(), ans.end());
            cout << ans;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}