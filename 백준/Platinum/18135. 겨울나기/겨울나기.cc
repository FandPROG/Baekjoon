#include <stdio.h>

using ll = long long;

int n, m;
ll arr[2000010];
int GP[2000010];
ll tree[8000010];
ll lazy[8000010];

void init(int st, int ed, int nd)
{
    if(st == ed) {
        tree[nd] = arr[st];
        return;
    }
    int mid = (st + ed) / 2;
    init(st, mid, nd * 2);
    init(mid + 1, ed, nd * 2 + 1);
    tree[nd] = tree[nd * 2] + tree[nd * 2 + 1];
}

void Push(int st, int ed, int nd)
{
    if(lazy[nd] != 0) {
        tree[nd] += (ed - st + 1) * lazy[nd];
        if(st != ed) {
            lazy[nd * 2] += lazy[nd];
            lazy[nd * 2 + 1] += lazy[nd];
        }
        lazy[nd] = 0;
    }
}

ll getSum(int st, int ed, int nd, int l, int r) {
    Push(st, ed, nd);
    if(ed < l || r < st) return 0;
    if(l <= st && ed <= r) return tree[nd];
    int mid = (st + ed) / 2;
    return getSum(st, mid, nd * 2, l, r) + getSum(mid + 1, ed, nd * 2 + 1, l, r);
}

void UpdateRange(int st, int ed, int nd, int l, int r, ll val) {
    Push(st, ed, nd);
    if(ed < l || r < st) return;
    if(l <= st && ed <= r) {
        tree[nd] = tree[nd] + val * (ed - st + 1);
        if (st != ed) {
            lazy[nd * 2] += val;
            lazy[nd * 2 + 1] += val;
        }
        return;
    }
    int mid = (st + ed) / 2;
    UpdateRange(st, mid, nd * 2, l, r, val);
    UpdateRange(mid + 1, ed, nd * 2 + 1, l, r, val);
    tree[nd] = tree[nd * 2] + tree[nd * 2 + 1];
}

int main()
{
    int i, j;
    scanf("%d %d", &n, &m);
    for(i = 1; i <= m; i++) {
        int x, y;
        ll z;
        scanf("%d %d %lld", &x, &y, &z);
        for(j = x; j <= y; ++j) {
            GP[j] = i;
        }
        arr[i] = z;
    }
    init(1, m, 1);
    while(1) {
        int type;
        scanf("%d", &type);
        if(type == 0) break;
        if(type == 1) {
            int x, y;
            scanf("%d %d", &x, &y);
            ll result = 0;
            if(x <= y) {
                result = getSum(1, m, 1, GP[x], GP[y]);
            } else {
                result = getSum(1, m, 1, GP[x], m) + getSum(1, m, 1, 1, GP[y]);
            }
            printf("%lld\n", result);
        } else if(type == 2) {
            int x, y;
            ll z;
            scanf("%d %d %lld", &x, &y, &z);
            if(x <= y) {
                UpdateRange(1, m, 1, GP[x], GP[y], z);
            } else {
                UpdateRange(1, m, 1, GP[x], m, z);
                UpdateRange(1, m, 1, 1, GP[y], z);
            }
        }
    }
    return 0;
}
