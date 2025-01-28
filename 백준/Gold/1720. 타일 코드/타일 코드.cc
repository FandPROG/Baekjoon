#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using lD = long double;
using D = double;

int n;
int dp[35];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, j;
    cin >> n;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 3;
    for(i=3;i<=n;i++) {
        dp[i] = dp[i - 1] + dp[i - 2] * 2;
    }
    if(n == 1)
        cout<< '1';
    else if(n % 2)
        cout << (dp[n] + dp[n / 2]) / 2;
    else
        cout << (dp[n] + dp[n / 2 + 1]) / 2;
}