#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n;
int arr[500010];
ll tree[2000010];
vector <pair<int, int>> vec;

ll getSum(int st, int ed, int nd, int l, int r)
{
    if(ed < l || r < st) return 0;
    if(l <= st && ed <= r) return tree[nd];
    int mid = (st + ed) / 2;
    return getSum(st, mid, nd * 2, l, r) + getSum(mid + 1, ed, nd * 2 + 1, l, r);
}

void Update(int st, int ed, int nd, int idx, ll val)
{
    if(idx < st || ed < idx) return;
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
    int i, j;
    scanf("%d", &n);
    for(i=0;i<n;i++) scanf("%d", &arr[i]);
    for(i=0;i<n;i++) {
        int x;
        scanf("%d", &x);
        vec.push_back({x, i});
    }
    sort(vec.begin(), vec.end());
    vector<int> value, index;
    for(i=0;i<vec.size();i++) {
        value.push_back(vec[i].first);
        index.push_back(vec[i].second);
    }
    ll ans = 0;
    for(i=0;i<n;i++) {
        int ces = lower_bound(value.begin(), value.end(), arr[i]) - value.begin();
        int idx = index[ces] + 1;
        Update(1, n, 1, idx, 1);
        if(idx < n) {
            ll res = getSum(1, n, 1, idx + 1, n);
            ans += res;
        }
    }
    printf("%lld", ans);
    return 0;
}