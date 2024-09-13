#include <stdio.h>

using ll = long long;

int n, Q;
ll arr[100010];
ll tree[400010];
ll lazy[400010];

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
    scanf("%d", &n);
    for(i=1;i<=n;i++) scanf("%lld", &arr[i]);
    init(1, n, 1);
    scanf("%d", &Q);
    while(Q--) {
        int type;
        scanf("%d", &type);
        if(type == 1) {
            int x, y;
            ll z;
            scanf("%d %d %lld", &x, &y, &z);
            update_range(1, n, 1, x, y, z);
        }
        else {
            int x;
            scanf("%d", &x);
            printf("%lld\n", sum(1, n, 1, x, x));
        }
    }
    return 0;
}