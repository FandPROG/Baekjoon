#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1000000007;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<long long> dp(5, 0), next(5, 0);
    dp[0] = 1;
    string pat = "MRDR";
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < 5; j++) next[j] = 0;
        for (int j = 0; j < 4; j++) {
            next[j] = (next[j] + dp[j] * 25LL) % MOD;
            next[j+1] = (next[j+1] + dp[j]) % MOD;
        }
        next[4] = (next[4] + dp[4] * 26LL) % MOD;
        
        dp = next;
    }
    cout << dp[4] << "\n";
    return 0;
}
