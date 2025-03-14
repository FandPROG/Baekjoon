#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using lD = long double;
using D = double;

int dx[2] = {0, 1};
int dy[2] = {1, 0};

int mp[110][110];
int dp[110][110];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, j;
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector <pair<int, int>> item;
    item.push_back({1, 1});
    for(i=0;i<a;i++) {
        int x, y;
        cin >> x >> y;
        mp[x][y] = 1;
        item.push_back({x, y});
    }
    item.push_back({n, m});
    sort(item.begin(), item.end());
    for(i=0;i<b;i++) {
        int x, y;
        cin >> x >> y;
        mp[x][y] = 2;
    }
    int ans = 1;
    for(int k = 1;k<item.size();k++) {
        
        for(i=item[k - 1].first;i<=item[k].first;i++) {
            for(j=item[k -1].second;j<=item[k].second;j++) {
                dp[i][j] = 0;
            }
        }

        dp[item[k-1].first][item[k-1].second] = 1;
        for(i=item[k - 1].first;i<=item[k].first;i++) {
            for(j=item[k -1].second;j<=item[k].second;j++) {
                for(int d = 0;d < 2;d++) {
                    int nx = i + dx[d], ny = j + dy[d];
                    if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
                    if(mp[nx][ny] == 2) continue;
                    dp[nx][ny] += dp[i][j];
                }
            }
        }

        ans *= dp[item[k].first][item[k].second];

    }
    cout << ans;
    return 0;
}