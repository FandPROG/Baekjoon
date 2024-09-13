
#include <stdio.h>
#include <algorithm>

using namespace std;

int n, m;
int arr[500010];
int tree[2000010];
int lazy[2000010];

void push(int st, int ed, int nd) {
    if(lazy[nd] != 0) {
        if((ed - st + 1) % 2) tree[nd] ^= lazy[nd];
        if(st != ed) {
            lazy[nd * 2] ^= lazy[nd];
            lazy[nd * 2 + 1] ^= lazy[nd];
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
    tree[nd] = tree[nd * 2] ^ tree[nd * 2 + 1];
}

int XorTree(int st, int ed, int nd, int l, int r) {
    push(st, ed, nd);
    if(l > ed || r < st) return 0;
    if(l <= st && ed <= r) return tree[nd];
    int mid = (st + ed) / 2;
    return XorTree(st, mid, nd * 2, l, r) ^ XorTree(mid + 1, ed, nd * 2 + 1, l, r);
}

void update_range(int st, int ed, int nd, int l, int r, int k) {
    push(st, ed, nd);
    if(ed < l || st > r) return;
    if(l <= st && ed <= r) {
        lazy[nd] ^= k;
        push(st, ed, nd);
        return;
    }
    int mid = (st + ed) / 2;
    update_range(st, mid, nd * 2, l, r, k);
    update_range(mid + 1, ed, nd * 2 + 1, l, r, k);
    tree[nd] = tree[nd * 2] ^ tree[nd * 2 + 1];
}

int main()
{
    int i, j;
    scanf("%d", &n);
    for(i=1;i<=n;i++) scanf("%d", &arr[i]);
    init(1, n, 1);
    scanf("%d", &m);
    for(i=0;i<m;i++) {
        int type, x, y, z;
        scanf("%d", &type);
        if(type == 1) {
            scanf("%d %d %d", &x, &y, &z);
            update_range(1, n, 1, x + 1, y + 1, z);
        }
        else {
            scanf("%d %d", &x, &y);
            printf("%d\n", XorTree(1, n, 1, x + 1, y + 1));
            
        }
    }
    return 0;
}