#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using lD = long double;
using D = double;

int n;
vector <int> arr;
set <int> check;

void dfs(int sum, int x)
{
    if(x >= n) {
        check.insert(sum);
        return;
    }
    dfs(sum + arr[x], x + 1);
    dfs(sum, x + 1);
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, j;
    cin >> n;
    ll ans = 1;
    for(i=0;i<n;i++) {
        int x;
        cin >> x;
        arr.push_back(x);
        ans += (ll)x;
    }
    dfs(0, 0);
    cout << ans - (ll)check.size();
}