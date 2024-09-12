#include <stdio.h>
#include <algorithm>

int arr[100010];
int tree[400010];
int lazy[400010];
int n, m;

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

void push(int st, int ed, int nd) {
    if(lazy[nd] != 0) {
        tree[nd] = (ed - st + 1) - tree[nd];
        if(st != ed) {
            lazy[nd * 2] = (lazy[nd * 2] + 1) % 2;
            lazy[nd * 2 + 1] = (lazy[nd * 2 + 1] + 1) % 2;
        }
        lazy[nd] = 0;
    }
}

int sum_res(int st, int ed, int nd, int l, int r) {
    push(st, ed, nd);
    if(l > ed || r < st) return 0;
    if(l <= st && ed <= r) return tree[nd];
    int mid = (st + ed) / 2;
    return sum_res(st, mid, nd * 2, l, r) + sum_res(mid + 1, ed, nd * 2 + 1 , l, r);
}

void update_range(int st, int ed, int nd, int l, int r) {
    push(st, ed, nd);
    if(ed < l || st > r) return;
    if(l <= st && ed <= r) {
        tree[nd] = (ed - st + 1) - tree[nd];
        if(st != ed) {
            lazy[nd * 2] = (lazy[nd * 2] + 1) % 2;
            lazy[nd * 2 + 1] = (lazy[nd * 2 + 1] + 1) % 2;
        }
        return;
    }
    int mid = (st + ed) / 2;
    update_range(st, mid, nd * 2, l, r);
    update_range(mid + 1, ed, nd * 2 + 1, l, r);
    tree[nd] = tree[nd * 2] + tree[nd * 2 + 1];
}


int main()
{
    int i, j;
    scanf("%d %d", &n, &m);
    for(i=0;i<m;i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        if(x == 0) update_range(1, n, 1, y, z);
        else printf("%d\n", sum_res(1, n, 1, y, z));
    }
    return 0;
}