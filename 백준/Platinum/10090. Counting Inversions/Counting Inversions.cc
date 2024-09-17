#include <stdio.h>

using ll = long long;

int arr[1000010];
ll tree[4000000];

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
    for(i=0;i<n;i++) scanf("%d", &arr[i]);
    ll ans = 0;
    for(i=0;i<n;i++) {
        Update(1, n, 1, arr[i], 1);
        if(arr[i] < n) {
            ans += getSum(1, n, 1, arr[i] + 1, n);
        }
    }
    printf("%lld", ans);
    return 0;
}