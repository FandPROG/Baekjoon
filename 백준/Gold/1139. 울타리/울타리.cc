#include <bits/stdc++.h>

using namespace std;

struct Samgak {
    int mask;
    double area;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> vec(N);
    for(int i = 0; i < N; i++) {
        cin >> vec[i];
    }
    vector<Samgak> samVec;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            for(int k = j + 1; k < N; k++) {
                int a = vec[i], b = vec[j], c = vec[k];
                int byon[3] = {a, b, c};
                sort(byon, byon + 3);
                if(byon[0] + byon[1] > byon[2]) {
                    double p = (byon[0] + byon[1] + byon[2]) / 2.0;
                    double area = sqrt(p * (p - byon[0]) * (p - byon[1]) * (p - byon[2]));
                    int mask = (1 << i) | (1 << j) | (1 << k);
                    samVec.push_back({mask, area});
                }
            }
        }
    }
    int T = 1 << N;
    vector<double> dp(T, 0);
    for(int mask = 0; mask < T; mask++) {
        for(Samgak tri : samVec) {
            if((mask & tri.mask) == 0) {
                int newMask = mask | tri.mask;
                dp[newMask] = max(dp[newMask], dp[mask] + tri.area);
            }
        }
    }
    double ans = 0.0;
    for(int mask = 0; mask < T; mask++) {
        ans = max(ans, dp[mask]);
    }
    
    cout << fixed << setprecision(9) << ans << "\n";
    return 0;
}
