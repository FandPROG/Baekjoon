#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using lD = long double;
using D = double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, j, k;

    string s;
    vector <string> ans;
    cin >> s;
    int n = s.size();
    i = 0;
    while(i < n) {
        j = i + 1;
        k = i;
        while(j < n && s[k] <= s[j]) {
            if(s[j] > s[k]) k = i;
            else k++;
            j++;
        }
        int block = j - k;
        while(i <= k) {
            ans.push_back(s.substr(i, block));
            i += block;
        }
    }
    vector<string> merged;
    string imsi = ans[0];
    merged.push_back( imsi );
    for(int i = 1; i < (int)ans.size(); i++) {
        if ( imsi == ans[i] ) {
            merged.back() += ans[i];
        } else {
            imsi = ans[i];
            merged.push_back( imsi );
        }
    }
    for(auto st : merged) {
        cout << '(' + st +')';
    }
    return 0;
}