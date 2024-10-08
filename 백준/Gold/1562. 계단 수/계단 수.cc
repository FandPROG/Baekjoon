#include <stdio.h>
#include <algorithm>

using namespace std;
using ll = long long;

const int MOD = 1000000000;
ll n;
ll dp[1 << 10][101][10];

ll stair(ll mask, ll pos, ll last_digit) {
    if(pos == n) {
        if(mask == (1 << 10) - 1) {
            return 1;
        }
        else return 0;
    }
    
    if (dp[mask][pos][last_digit] != -1) return dp[mask][pos][last_digit];
    
    dp[mask][pos][last_digit] = 0;
    if (last_digit > 0) {
        dp[mask][pos][last_digit] = (dp[mask][pos][last_digit] + stair(mask | (1 << (last_digit - 1)), pos + 1, last_digit - 1)) % MOD;
    }
    if (last_digit < 9) {
        dp[mask][pos][last_digit] = (dp[mask][pos][last_digit] + stair(mask | (1 << (last_digit + 1)), pos + 1, last_digit + 1)) % MOD;
    }
    
    return dp[mask][pos][last_digit];
}

int main() {
    scanf("%lld", &n);
    ll ans = 0;
    
    for (int i = 0; i < (1 << 10); i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k < 10; k++) {
                dp[i][j][k] = -1;
            }
        }
    }
    
    for (int i = 1; i <= 9; i++) {
        ans = (ans + stair(1 << i, 1, i)) % MOD;
    }
    
    printf("%lld\n", ans);
    return 0;
}