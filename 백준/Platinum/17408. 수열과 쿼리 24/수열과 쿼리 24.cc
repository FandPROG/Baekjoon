#include <stdio.h>
#include <algorithm>

using namespace std;

struct dat{
    int x, y;
};

int n, q;
int arr[100010];
dat tree[400010];

dat merge(dat a, dat b)
{
    dat imsi;
    if(a.x < b.x) {
        swap(a, b);
    }
    imsi.x = a.x;
    imsi.y = max(a.y, b.x);
    return imsi;
}

void update(int st, int ed, int nd, int idx, int v)
{
    if(idx < st || idx > ed) return;
    if(st == ed) {
        tree[nd] = {v, 0};
        return;
    }
    int mid = (st + ed) / 2;
    update(st, mid, nd * 2, idx, v);
    update(mid + 1, ed, nd * 2 + 1, idx, v);
    tree[nd] = merge(tree[nd * 2], tree[nd * 2 + 1]);
}

dat getSum(int st, int ed, int nd, int l, int r)
{
    if(ed < l || r < st) return {0, 0};
    if(l <= st && ed <= r) return tree[nd];
    int mid = (st + ed) / 2;
    return merge(getSum(st, mid, nd * 2, l, r), getSum(mid + 1, ed, nd * 2 + 1, l, r));
}

int main()
{
    int i, j;
    scanf("%d", &n);
    for(i=1;i<=n;i++) {
        scanf("%d", &arr[i]);
        update(1, n, 1, i, arr[i]);
    }
    scanf("%d", &q);
    while(q--) {
        int type;
        scanf("%d", &type);
        if(type == 1) {
            int x, y;
            scanf("%d %d", &x, &y);
            update(1, n, 1, x, y);
        }
        else {
            int x, y;
            scanf("%d %d", &x, &y);
            dat res = getSum(1, n, 1, x, y);
            printf("%d\n", res.x + res.y);
        }
    }
    return 0;
}