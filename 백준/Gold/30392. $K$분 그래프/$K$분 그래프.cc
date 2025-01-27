#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using lD = long double;
using D = double;

int n, m, k;
int cnt[300010];
int nd[300010];
bool boolean = true;
vector <pair<int, int>> vec[300010];

void dfs(int x, int val) {
    for(int i=0;i<vec[x].size();i++) {
        int idx = vec[x][i].first, nval = (val + vec[x][i].second) % k;
        if(cnt[idx] == 0) {
            nd[idx] = nval;
            cnt[idx] = 1;
            dfs(idx, nval);
        }
        else if(nd[idx] != nval) {
            boolean = false;
            return;
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, j;
    cin >> n >> m >> k;
    for(i=0;i<m;i++) {
        int x, y, z;
        cin >> x >> y >> z;
        vec[x].push_back({y, z});
        vec[y].push_back({x, z});
    }
    for(i=1;i<=n;i++) {
        if(cnt[i] == 0) {
            dfs(i, 0);
            if(!boolean) {
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";
    return 0;
}