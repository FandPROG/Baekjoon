#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int n, m, k;
ll arr[1000010];
ll tree[4000010];
ll lazy[4000010];

void push(int st, int ed, int nd) {
    if(lazy[nd] != 0) {
        tree[nd] += (ed - st + 1) * lazy[nd];
        if(st != ed) {
            lazy[nd * 2] += lazy[nd];
            lazy[nd * 2 + 1] += lazy[nd];
        }
        lazy[nd] = 0;
    }
}

void init(int st, int ed, int nd) {
    if(st == ed) {
        tree[nd] = arr[st];
        return;
    }
    int mid = (st + ed) / 2;
    init(st, mid, nd * 2);
    init(mid + 1, ed, nd * 2 + 1);
    tree[nd] = tree[nd * 2] + tree[nd * 2 + 1];
}

ll sum(int st, int ed, int nd, int l, int r) {
    push(st, ed, nd);
    if(l > ed || r < st) return 0;
    if(l <= st && ed <= r) return tree[nd];
    int mid = (st + ed) / 2;
    return sum(st, mid, nd * 2, l, r) + sum(mid + 1, ed, nd * 2 + 1, l, r);
}

void update_range(int st, int ed, int nd, int l, int r, ll val) {
    push(st, ed, nd);
    if(ed < l || st > r) return;
    if(l <= st && ed <= r) {
        lazy[nd] += val;
        push(st, ed, nd);
        return;
    }
    int mid = (st + ed) / 2;
    update_range(st, mid, nd * 2, l, r, val);
    update_range(mid + 1, ed, nd * 2 + 1, l, r, val);
    tree[nd] = tree[nd * 2] + tree[nd * 2 + 1];
}

int main()
{
    int i, j;
    scanf("%d %d %d", &n, &m, &k);
    for(i=1;i<=n;i++) scanf("%lld", &arr[i]);
    init(1, n, 1);
    for(i=0;i<m + k;i++) {
        int ch, x, y;
        ll val;
        scanf("%d", &ch);
        if(ch == 1) {
            scanf("%d %d %lld", &x, &y, &val);
            update_range(1, n, 1, x, y, val);
        }
        if(ch == 2) {
            scanf("%d %d", &x, &y);
            printf("%lld\n", sum(1, n, 1, x, y));
        }
    }
    return 0;
}