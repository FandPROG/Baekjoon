#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int N, U, V;

struct Nd {
    ll lmx, rmx, mx, sm;
    Nd() {
        lmx = rmx = mx = sm = -2e9;
    }
    void set(int x)
    {
        lmx = rmx = mx = sm = x * U + V;
    }
};

Nd Calcu(Nd left, Nd right) {
    Nd res;
    res.lmx = max(left.lmx, left.sm + right.lmx);

    res.rmx = max(right.rmx, right.sm + left.rmx);

    res.mx = max(max(left.mx, right.mx), left.rmx + right.lmx);

    res.sm = left.sm + right.sm;
    return res;
}

int arr[100010];
Nd tree[400010];

void init(int s, int e, int nd)
{
    if(s == e) {
        tree[nd].set(arr[s]);
        return;
    }
    int mid = (s + e) / 2;
    init(s, mid, nd * 2);
    init(mid + 1, e, nd * 2 + 1);
    tree[nd] = Calcu(tree[nd * 2], tree[nd * 2 + 1]);
}

void Update(int s, int e, int nd, int idx, ll val)
{
    if(idx < s || e < idx) return;
    if(s == e) {
        tree[nd].set(val);
        return;
    }
    int mid = (s + e) / 2;
    Update(s, mid, nd * 2, idx, val);
    Update(mid + 1, e, nd * 2 + 1, idx, val);
    tree[nd] = Calcu(tree[nd * 2], tree[nd * 2 + 1]);
}

Nd getSum(int s, int e, int nd, int l, int r)
{
    if(e < l || r < s) return Nd();
    if(l <= s && e <= r) return tree[nd];
    int mid = (s + e) / 2;
    return Calcu(getSum(s, mid, nd * 2, l, r), getSum(mid + 1, e, nd * 2 + 1, l, r));
}

int main()
{
    int i, j;
    int Q;
    scanf("%d %d %d %d", &N, &Q, &U, &V);
    for(i=1;i<=N;i++) scanf("%d", &arr[i]);
    init(1, N, 1);
    while(Q--) {
        int x;
        scanf("%d", &x);
        if(x == 0) {
            int l, r;
            scanf("%d %d", &l, &r);
            printf("%lld\n", getSum(1, N, 1, l, r).mx - V);
        }
        else {
            int idx;
            ll val;
            scanf("%d %lld", &idx, &val);
            Update(1, N, 1, idx, val);
        }
    }
    return 0;
}