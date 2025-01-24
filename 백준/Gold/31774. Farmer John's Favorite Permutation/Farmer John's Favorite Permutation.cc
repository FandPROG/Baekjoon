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
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector <int> vec(n - 1), check(n + 1);
        for(i=0;i<n - 1;i++) {
            cin >> vec[i];
            check[vec[i]]++;
        }
        if(vec[n - 2] != 1) {
            cout << "-1" << "\n";
            continue;
        }
        vec.pop_back();
        check[1]--;
        vector <int> ans(n), zeronum;
        for(i=1;i<=n;i++) {
            if(check[i] == 0) zeronum.push_back(i);
        }
        if(zeronum.size() > 2) {
            cout << "-1" << "\n";
            continue;
        }
        ans[0] = zeronum[0], ans[n - 1] = zeronum[1];
        int l = 0, r = n - 1;
        for(i=0;i<n - 2;i++) {
            if(ans[l] > ans[r]) {
                ans[l + 1] = vec[i];
                l++;
            }
            else {
                ans[r - 1] = vec[i];
                r--;
            }
        }
        for(auto printans : ans) {
            cout << printans << ' ';
        }
        cout << "\n";
    }
    return 0;
}