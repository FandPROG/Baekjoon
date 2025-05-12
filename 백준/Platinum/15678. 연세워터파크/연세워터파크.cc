#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, D;
    cin >> N >> D;
    vector<ll> K(N+1), dp(N+1);
    for(int i = 1; i <= N; i++){
        cin >> K[i];
    }
    deque<int> dq;
    ll answer = LLONG_MIN;
    for(int i = 1; i <= N; i++) {
        while (!dq.empty() && dq.front() < i - D) dq.pop_front();
        ll best_prev = dq.empty() ? 0LL : dp[dq.front()];
        dp[i] = K[i] + max(0LL, best_prev);
        while (!dq.empty() && dp[dq.back()] <= dp[i]) dq.pop_back();

        dq.push_back(i);
        answer = max(answer, dp[i]);
    }
    cout << answer << "\n";
    return 0;
}
