#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

struct Nd{
    ll lmx, rmx, mx, sm;
    Nd() {
        lmx = rmx = mx = sm = -2e9;
    }
    void set(int x) {
        lmx = rmx = mx = sm = x;
    }
};

int n;
ll arr[100010];
Nd tree[400000];

Nd Calcu(Nd left, Nd right) {
    Nd res;
    res.lmx = max(left.lmx, left.sm + right.lmx);
    res.rmx = max(right.rmx, right.sm + left.rmx);
    res.mx = max(max(left.mx, right.mx), left.rmx + right.lmx);
    res.sm = left.sm + right.sm;
    return res;
}

void init(int st, int ed, int nd)
{
    if(st == ed) {
        tree[nd].set(arr[st]);
        return;
    }
    int mid = (st + ed) / 2;
    init(st, mid, nd * 2);
    init(mid + 1, ed, nd * 2 + 1);
    tree[nd] = Calcu(tree[nd * 2], tree[nd * 2 + 1]);
}

Nd getSum(int st, int ed, int nd, int l, int r)
{
    if(ed < l || r < st) return Nd();
    if(l <= st && ed <= r) return tree[nd];
    int mid = (st + ed) / 2;
    return Calcu(getSum(st, mid, nd * 2, l, r), getSum(mid + 1, ed, nd * 2 + 1, l, r));
}

int main()
{
    int i, j;
    scanf("%d", &n);
    for(i=1;i<=n;i++) scanf("%d", &arr[i]);
    init(1, n, 1);
    int m;
    scanf("%d", &m);
    while(m--) {
        int x, y;
        scanf("%d %d", &x, &y);
        Nd ans = getSum(1, n, 1, x, y);
        printf("%lld\n", ans.mx);
    }
    return 0;
}