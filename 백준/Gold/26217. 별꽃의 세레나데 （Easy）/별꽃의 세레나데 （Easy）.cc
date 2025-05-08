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
    lD ans = 0;
    for(i=1;i<=n;i++) {
        ans += lD(n) / lD(i);
    }
    cout << ans;
    return 0;
}