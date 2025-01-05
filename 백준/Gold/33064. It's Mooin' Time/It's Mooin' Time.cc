#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;

int n, f;
string s;
map <string, int> mp;
set <string> ans, st;

void ReRange(int l, int r, int val)
{
    for(int i=l;i<=r - 2;i++) {
        string res;
        res += s[i];
        res += s[i + 1];
        res += s[i + 2];
        if(res[0] != res[1] && res[1] == res[2]) {
            mp[res] += val;
        }
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int i, j;
    cin >> n >> f;
    cin >> s;
    ReRange(0, n - 1, 1);
    for(i=0;i<n;i++) {
        char now = s[i];
        map<string, int> imsi = mp;
        for(char ch = 'a';ch <= 'z';ch++) {
            int l = i - 2, r = i + 2;
            if(l < 0) l = 0;
            if(r >= n) r = n - 1;
            ReRange(l, r, -1);
            s[i] = ch;
            ReRange(l, r, 1);
            for(auto itr = mp.begin();itr != mp.end();itr++) {
                if(itr->second >= f) {
                    ans.insert(itr->first);
                }
            }
        }
        mp = imsi;
        s[i] = now;
    }
    cout << ans.size() << '\n';
    for(auto itr = ans.begin();itr!=ans.end();itr++) {
        cout << *itr << '\n';
    }
    return 0;
}