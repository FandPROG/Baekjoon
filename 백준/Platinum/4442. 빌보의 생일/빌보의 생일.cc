#include <algorithm>
#include <string>
#include <map>
#include <iostream>
#include <vector>

using namespace std;

int tree[400000];

int getSum(int st, int ed, int nd, int l, int r)
{
    if(ed < l || r < st) return 0;
    if(l <= st && ed <= r) return tree[nd];
    int mid = (st + ed) / 2;
    return getSum(st, mid, nd * 2, l, r) + getSum(mid + 1, ed, nd * 2 + 1, l, r);
}

void Update(int st, int ed, int nd, int idx, int val)
{
    if(ed < idx || idx < st) return;
    if(st == ed) {
        tree[nd] += val;
        return;
    }
    int mid = (st + ed) / 2;
    Update(st, mid, nd * 2, idx, val);
    Update(mid + 1, ed, nd * 2 + 1, idx, val);
    tree[nd] = tree[nd * 2] + tree[nd * 2 + 1];
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    while(1) {
        vector <string> vec;
        map <string, int> mp;
        int n;
        cin >> n;
        if(n == 0) break;
        for(int i=0;i<n * 4;i++) tree[i] = 0;
        for(int i=0;i<n;i++) {
            string s;
            cin >> s;
            vec.push_back(s);
        }
        for(int i=0;i<n;i++) {
            string s;
            cin >> s;
            mp.insert({s, i + 1});
        }
        long long ans = 0;
        for(int i=0;i<n;i++) {
            int idx = mp[vec[i]];
            Update(1, n, 1, idx, 1);
            if(idx < n) {
                ans += getSum(1, n, 1, idx + 1, n);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}