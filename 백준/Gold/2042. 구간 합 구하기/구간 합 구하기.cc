#include <stdio.h>
#include <algorithm>
#include <vector>

using ll = long long;
using namespace std;

int n, m, k;
ll arr[1000010];
ll tree[4000010];

void init(int s, int e, int nd)
{
    if(s == e) {
        tree[nd] = arr[s];
        return;
    }
    int mid = (s + e) / 2;
    init(s, mid, nd * 2);
    init(mid + 1, e, nd * 2 + 1);
    tree[nd] = tree[nd * 2] + tree[nd * 2 + 1];
}

ll getSum(int s, int e, int l, int r, int nd)
{
    if(l > e || s > r) return 0;
    if(l <= s && e <= r) return tree[nd];
    int mid = (s + e) / 2;
    return getSum(s, mid, l, r, nd * 2) + getSum(mid + 1, e, l, r, nd * 2 + 1);
}

void UpdateTree(int s, int e, int nd, int idx, ll val)
{
    if(e < idx || s > idx) return;
    if(s == e) {
        tree[nd] = val;
        return;
    }
    int mid = (s + e) / 2;
    UpdateTree(s, mid, nd * 2, idx, val);
    UpdateTree(mid + 1, e, nd * 2 + 1, idx, val);
    tree[nd] = tree[nd * 2] + tree[nd * 2 + 1];
}

int main()
{
    int i, j;
    scanf("%d %d %d", &n, &m, &k);
    for(i=1;i<=n;i++) scanf("%lld", &arr[i]);
    init(1, n, 1);
    for(i=0;i<m + k;i++) {
        int x;
        scanf("%d", &x);
        if(x == 1) {
            int idx;
            ll val;
            scanf("%d %lld", &idx, &val);
            UpdateTree(1, n, 1, idx, val);
        }
        else {
            int l, r;
            scanf("%d %d", &l, &r);
            printf("%lld\n", getSum(1, n, l, r, 1));
        }
    }
    return 0;
}