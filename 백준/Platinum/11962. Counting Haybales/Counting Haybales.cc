#include <stdio.h>
#include <algorithm>

using namespace std;

using ll = long long;

int n, m;
int arr[200010];
ll tree[800010];
ll lazy[800010];

ll mintree[800010];
ll minlazy[800010];

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

void min_init(int st, int ed, int nd) {
    if(st == ed) {
        mintree[nd] = arr[st];
        return;
    }
    int mid = (st + ed) / 2;
    min_init(st, mid, nd * 2);
    min_init(mid + 1, ed, nd * 2 + 1);
    mintree[nd] = min(mintree[nd * 2], mintree[nd * 2 + 1]);
}

void minPush(int st, int ed, int nd) {
    if(minlazy[nd] != 0) {
        mintree[nd] += minlazy[nd];
        if(st != ed) {
            minlazy[nd * 2] += minlazy[nd];
            minlazy[nd * 2 + 1] += minlazy[nd];
        }
        minlazy[nd] = 0;
    }
}

ll min_range(int st, int ed, int nd, int l, int r) {
    minPush(st, ed, nd);
    if(ed < l || r < st) return 2e15;
    if(l <= st && ed <= r) return mintree[nd];
    int mid = (st + ed) / 2;
    return min(min_range(st, mid, nd * 2, l, r), min_range(mid + 1, ed, nd * 2 + 1, l, r));
}

void min_update_range(int st, int ed, int nd, int l, int r, ll val) {
    minPush(st, ed, nd);
    if(ed < l || r < st) return;
    if(l <= st && ed <= r) {
        minlazy[nd] += val;
        minPush(st, ed, nd);
        return;
    }
    int mid = (st + ed) / 2;
    min_update_range(st, mid, nd * 2, l, r, val);
    min_update_range(mid + 1, ed, nd * 2 + 1, l, r, val);
    mintree[nd] = min(mintree[nd * 2], mintree[nd * 2 + 1]);
}

int main()
{
    int i, j;
    scanf("%d %d", &n, &m);
    for(i=1;i<=n;i++) scanf("%d", &arr[i]);
    init(1, n, 1);
    min_init(1, n, 1);
    for(i=0;i<m;i++) {
        int x, y;
        ll k;
        char c;
        scanf(" %c", &c);
        if(c == 'M') {
            scanf("%d %d", &x, &y);
            printf("%lld\n", min_range(1, n, 1, x, y));
        }
        if(c == 'S') {
            scanf("%d %d", &x, &y);
            printf("%lld\n", sum(1, n, 1, x, y));
        }
        if(c == 'P') {
            scanf("%d %d %lld", &x, &y, &k);
            update_range(1, n, 1, x, y, k);
            min_update_range(1, n, 1, x, y, k);
        }
    }
    return 0;
}