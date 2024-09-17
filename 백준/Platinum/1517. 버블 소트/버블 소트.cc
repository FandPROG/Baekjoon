#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

vector <ll> vec;
ll arr[500010];
ll tree[2000000];

void Update(int st, int ed, int nd, int idx, int val)
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

ll getSum(int st, int ed, int nd, int l, int r)
{
    if(ed < l || r < st) return 0;
    if(l<=st && ed <= r) return tree[nd];
    int mid = (st + ed) / 2;
    return getSum(mid + 1, ed, nd * 2 + 1, l, r) + getSum(st, mid, nd * 2, l, r);
}

int main()
{
    int i, j;
    int n;
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        scanf("%lld", &arr[i]);
        vec.push_back(arr[i]);
    }
    sort(vec.begin(), vec.end());
    vector <int> v;
    ll bck = -2e10;
    for(i=0;i<n;i++) {
        if(bck == vec[i]) continue;
        v.push_back(vec[i]);
        bck = vec[i];
    }
    ll ans = 0;
    int vsz = v.size();
    for(i=0;i<n;i++) {
        int idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
        idx++;
        Update(1, vsz, 1, idx, 1);
        if(idx < vsz) {
            ans += getSum(1, vsz, 1, idx + 1, n);
        }
    }
    printf("%lld", ans);
    return 0;
}