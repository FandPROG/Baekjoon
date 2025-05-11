#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using lD = long double;
using D = double;

int n, t;
int ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, j;
    deque <pair<int, int>> ndq, xdq;
    cin >> t >> n;
    int l = 0, r = 0;
    while(r < n) {
        int now;
        cin >> now;
        while(1) {
            if(ndq.empty() || now > ndq.back().first) {
                break;
            }
            else {
                ndq.pop_back();
            }
        }
        ndq.push_back({now, r});
        while(1) {
            if(xdq.empty() || now < xdq.back().first) {
                break;
            }
            else {
                xdq.pop_back();
            }
        }
        xdq.push_back({now, r});
        if(xdq.front().first - ndq.front().first > t) {
            l++;
            while (!xdq.empty() && xdq.front().second < l) xdq.pop_front();
            while (!ndq.empty() && ndq.front().second < l) ndq.pop_front();
        }
        r++;
        ans = max(r - l, ans);
    }
    cout << ans;
    return 0;
}