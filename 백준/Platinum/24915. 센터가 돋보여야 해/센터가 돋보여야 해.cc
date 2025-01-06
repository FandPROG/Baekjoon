#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

struct Nd{
    ll mx, mn, Lans, Rans, ans;
    Nd() {
        mx = Lans = Rans = ans = -2e11;
        mn = 2e11;
    }
    void set(ll x) {
        mx = mn = x;
        ans = Lans = Rans = -2e11;
    }
};

Nd Calcu(Nd left, Nd right)
{
    Nd res;
    res.mx = max(left.mx, right.mx);
    res.mn = min(left.mn, right.mn);
    res.Rans = max(right.Rans, right.mx - left.mn);
    res.Lans = max(left.Lans, left.mx - right.mn);
    res.ans = max(left.ans, max(right.ans, max(left.Rans - right.mn, right.Lans - left.mn)));
    return res;
}

int n;
ll arr[350000];
Nd tree[1500000];

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
    if(idx < s || idx > e) return;
    if(s == e) {
        tree[nd].set(val);
        return;
    }
    int mid = (s + e) / 2;
    Update(s, mid, nd * 2, idx, val);
    Update(mid + 1, e, nd * 2 + 1, idx, val);
    tree[nd] = Calcu(tree[nd * 2], tree[nd * 2 + 1]);
}

Nd getans(int s, int e, int nd, int l, int r)
{
    if(l > e || s > r) return Nd();
    if(l <= s && e <= r) return tree[nd];
    int mid = (s + e) / 2;
    return Calcu(getans(s, mid, nd * 2, l, r), getans(mid + 1, e, nd * 2 + 1, l, r));
}

int main()
{
    int i, j;
    int Q;
    scanf("%d %d", &n, &Q);
    for(i=1;i<=n;i++) scanf("%lld", &arr[i]);
    init(1, n, 1);
    while(Q--) {
        int x;
        scanf("%d", &x);
        if(x == 1) {
            int idx;
            ll val;
            scanf("%d %lld", &idx, &val);
            Update(1, n, 1, idx, val);
        }
        else {
            int l, r;
            scanf("%d %d", &l, &r);
            Nd res = getans(1, n, 1, l, r);
            printf("%lld\n", res.ans);
        }
    }
    return 0;
}