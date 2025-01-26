#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using lD = long double;
using D = double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, j;
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        string s1;
        int cntone = 0;
        int cntzero = 0;
        int checkone = 0;
        bool iszeroexist = 0;
        for(i=0;i<n;i++) {
            if(s[i] == '0') iszeroexist = 1;
            if(s[i] == '1' && cntzero == 0) {
                cntone++;
            }
            else if(s[i] == '0' && cntone >= 1 && checkone == 0) {
                cntzero++;
            }
            else if(s[i] == '1' && cntzero >= 1) {
                checkone = 1;
            }
            if(cntone >= 1) {
                s1 += s[i];
            }
        }
        if(cntone < 1) {
            cout << '0' << "\n";
            continue;
        }
        string s2;
        if(cntzero == 0) {
            if(iszeroexist)
                for(i=0;i<s1.size();i++) s2 += '0';
            else {
                for(i=0;i<s1.size() - 1;i++) s2 += '0';
                s2 += '1';
            }
        }
        else {
            for(i=0;i<cntone;i++) {
                s2 += '0';
            }
            if(cntone >= cntzero) {
                int idx = cntone - cntzero;
                while(1) {
                    s2 += s1[idx++];
                    if(s2.size() == s1.size()) break;
                }
            }
            else {
                for(i=0;i<s1.size() - cntone;i++) {
                    s2 += s1[i];
                }
            }
        }
        string ans;
        for(i=0;i<s1.size();i++) {
            if(s1[i] != s2[i]) ans += '1';
            else ans += '0';
        }
        cout << ans << "\n";
    }
    return 0;
}