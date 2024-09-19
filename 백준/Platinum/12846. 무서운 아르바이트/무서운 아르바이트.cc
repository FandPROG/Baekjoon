#include <stdio.h>
#include <algorithm>

using ll = long long;
using namespace std;

int n;
int arr[100010];
int tree[400000];

void init(int st, int ed, int nd)
{
    if(st == ed) {
        tree[nd] = st;
        return;
    }
    int mid = (st + ed) / 2;
    init(st, mid, nd * 2);
    init(mid + 1, ed, nd * 2 + 1);
    if(arr[tree[nd * 2]] < arr[tree[nd * 2 + 1]]) tree[nd] = tree[nd * 2];
    else tree[nd] = tree[nd * 2 + 1];
}

int gMin(int st, int ed, int nd, int l, int r)
{
    if(st > r || ed < l) return 0;
    if(l <= st && ed <= r) return tree[nd];
    int mid = (st + ed) / 2;
    int res1 = gMin(st, mid, nd * 2, l, r);
    int res2 = gMin(mid + 1, ed, nd * 2 + 1, l, r);
    if(arr[res1] < arr[res2]) return res1;
    else return res2;
}

ll getans(int st, int ed)
{
    int idx = gMin(1, n, 1, st, ed);
    ll res = (ll)arr[idx] * (ll)(ed - st + 1);
    if(st < idx) {
        res = max(res, getans(st, idx - 1));
    }
    if(idx < ed) {
        res = max(res, getans(idx + 1, ed));
    }
    return res;
}

int main()
{
    int i, j;
    scanf("%d", &n);
    for(i=1;i<=n;i++) scanf("%d", &arr[i]);
    arr[0] = 2e9;
    init(1, n, 1);
    ll ans = getans(1, n);
    printf("%lld", ans);
    return 0;
}