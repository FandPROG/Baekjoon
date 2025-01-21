#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll dp[5][50010];
ll sm[50010];

int main()
{
    int n;
    cin >> n;
    vector <ll> arr(n + 1);
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
        sm[i] = sm[i - 1] + arr[i];
    }
    int k;
    cin >> k;
    for(int i=1;i<=3;i++) {
        for(int j=k * i;j<=n;j++) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - k] + (sm[j] - sm[j - k]));
        }
    }
    cout << dp[3][n];
    return 0;
}