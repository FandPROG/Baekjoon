#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int ceilLog2(ll x) {
    int r = 0;
    ll p = 1;
    while(p < x) {
        p <<= 1;
        r++;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    int T = K + N - 1; 
    int r1 = ceilLog2(T + 1);
    int r2 = ceilLog2(N) + 1;
    int r = min(r1, r2);
    vector<pair<int, vector<int>>> moves(r, {0, {}});
    vector<int> candS(r, 0);
    if(r == r1) {
        for(int j = 0; j < r; j++) {
            candS[j] = (1 << j);
        }
        for(int i = 1; i <= N; i++) {
            int a = K + i - 1;
            for (int j = 0; j < r; j++) {
                if(a & (1 << j)) {
                    moves[j].second.push_back(i);
                }
            }
        }
        for(int j = 0; j < r; j++) {
            moves[j].first = candS[j];
        }
    }
    else {
        for(int j = 0; j < r - 1; j++) {
            candS[j] = (1 << j);
        }
        candS[r - 1] = T - ((1 << (r - 1)) - 1);
        for(int i = 1; i <= N; i++) {
            int a = K + i - 1;
            bool useUpper = false;
            int rem = a;
            if(a >= candS[r - 1]) {
                useUpper = true;
                rem = a - candS[r - 1];
            }
            for(int j = 0; j < r - 1; j++) {
                if(rem & (1 << j)) {
                    moves[j].second.push_back(i);
                }
            }
            if(useUpper) {
                moves[r - 1].second.push_back(i);
            }
        }
        for(int j = 0; j < r; j++) {
            moves[j].first = candS[j];
        }
    }
    cout << r << "\n";
    for(int j = 0; j < r; j++) {
        cout << moves[j].second.size() << " " << moves[j].first << "\n";
        for(int k = 0; k < moves[j].second.size(); k++) {
            cout << moves[j].second[k] << (k+1 == moves[j].second.size() ? "\n" : " ");
        }
    }
    return 0;
}
