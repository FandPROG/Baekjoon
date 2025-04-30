#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lD = long double;
using D = double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string ss;
        cin >> ss;
        int n = ss.size();
        string s = ss + ss;
        int i = 0, ans = 0;
        while (i < n) {
            ans = i;
            int j = i + 1, k = i;
            while (j < 2 * n && s[k] <= s[j]) {
                if (s[k] < s[j])
                    k = i;
                else
                    ++k;
                ++j;
            }
            int block = j - k;
            while (i <= k)
                i += block;
        }
        cout << s.substr(ans, n) << '\n';
    }
    return 0;
}
