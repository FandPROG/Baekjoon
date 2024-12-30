#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

struct Nd{
    ll lmx, rmx, mx, sm;
    Nd() {
        lmx = rmx = mx = (ll)-1e18;
        sm = 0;
    }
    void set(ll x) {
        lmx = rmx = mx = sm = x;
    }
};
int N;
ll A[100010];
Nd tree[400010];

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
        tree[nd].set(A[st]);
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
    scanf("%d", &N);
    for(i=1;i<=N;i++) scanf("%lld", &A[i]);
    init(1, N, 1);
    int Q;
    scanf("%d", &Q);
    while(Q--) {
        int x1, x2, y1, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if(y1 < x2) {
            Nd res1 = getSum(1, N, 1, x1, y1);
            Nd res2 = getSum(1, N, 1, x2, y2);
            Nd res3 = getSum(1, N, 1, y1 + 1, x2 - 1);
            printf("%lld\n", res1.rmx + res2.lmx + res3.sm);    
        }
        else {
            Nd res1 = getSum(1, N, 1, x2, y1);
            Nd res2 = getSum(1, N, 1, x1, x2 - 1);
            Nd res3 = getSum(1, N, 1, x2, y2);
            Nd res4 = getSum(1, N, 1, x1, y1);
            Nd res5 = getSum(1, N, 1, y1 + 1, y2);
            printf("%lld\n", max(res1.mx, max(res2.rmx + res3.lmx, res4.rmx + res5.lmx)));
        }
    }
    return 0;
}