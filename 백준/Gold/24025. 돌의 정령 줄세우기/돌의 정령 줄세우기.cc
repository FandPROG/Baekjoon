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
    vector <int> vec(n);

    for(i=0;i<n;i++) cin >> vec[i];
    if(vec[n - 1] < 0) {
        cout << "-1";
        return 0;
    }
    vector <int> ans;
    for(i=n;i>=1;i--) ans.push_back(i);
    int L = 0, isminus = 0;
    for(i=0;i<n;i++) {
        if(isminus == 0 && vec[i] < 0) {
            isminus = 1;
            L = i;
        }
        if(isminus == 1 && vec[i] > 0) {
            reverse(ans.begin() + L, ans.begin() + i + 1);
            isminus = 0;
        }
    }
    for(auto res : ans) cout << res << ' ';
    return 0;
}