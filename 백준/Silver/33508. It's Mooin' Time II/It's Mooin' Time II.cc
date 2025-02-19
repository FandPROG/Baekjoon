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
    vector <ll> arr(n + 1);
    vector <ll> ver(n + 1), cnt(n + 2);
    vector <pair<int, int>> sec(n + 1);
    for(i=1;i<=n;i++) cin >> arr[i];
    for(i=1;i<=n;i++) {
        ver[i] = ver[i - 1];
        if(cnt[arr[i]] == 0) {
            ver[i]++;
            sec[arr[i]].first = i;
        }
        cnt[arr[i]]++;
        if(cnt[arr[i]] >= 2) {
            sec[arr[i]].second = sec[arr[i]].first;
            sec[arr[i]].first = i;
        }
    }
    ll ans = 0;
    for(i=1;i<=n;i++) {
        if(cnt[i] >= 2) {
            ans += ver[sec[i].second] - 1;
        }
    }

    cout << ans;
    return 0;
}