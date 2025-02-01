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
    vector <ll> vec(n);
    for(i=0;i<n;i++) cin >> vec[i];
    vector <ll> zeroGroup;
    int check = 0;
    zeroGroup.push_back(0);
    ll ans = 0;
    for(i=0;i<n;i++) {
        if(vec[i] == 0) {
            zeroGroup.back()++;
        }
        if(i > 0 && vec[i - 1] == 0 && vec[i] > 0) {
            zeroGroup.push_back(0);
        }
        if(vec[i] > 0) ans += vec[i];
    }
    if(zeroGroup.size() > 1 && vec[0] == vec.back() && vec[0] == 0) {
        zeroGroup[0] += zeroGroup.back();
        zeroGroup.pop_back();
    }
    for(i=0;i<zeroGroup.size();i++) {
        ans += (zeroGroup[i] + 1) / 2;
    }
    cout << ans;
    return 0;
}