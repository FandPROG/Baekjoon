#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

struct Nd {
    ll l, r, mx, mn;
    Nd() {
        r = -1e9;
        l = 1e9;
        mx = -2e9, mn = 2e9;
    }
    void set(ll x) {
        l = r = mx = mn = x;
    }  
};

Nd Calcu(Nd left, Nd right) {
    Nd res;
    res.mx = max(left.mx, right.mx);
    res.mn = min(left.mn, right.mn);

    if(left.r - left.l > right.r - right.l) 
            res.l = left.l, res.r = left.r;
    else
        res.l = right.l, res.r = right.r;
    
    if(right.mx - left.mn > res.r - res.l) 
        res.r = right.mx, res.l = left.mn;
    
    return res;
}

ll n;
ll arr[100010];
Nd tree[400010];

void init(ll s, ll e, ll nd)
{
    if(s == e) {
        tree[nd].set(arr[s]);
        return;
    }
    ll mid = (s + e) / 2;
    init(s, mid, nd * 2);
    init(mid + 1, e, nd * 2 + 1);
    tree[nd] = Calcu(tree[nd * 2], tree[nd * 2 + 1]);
}

void UpdateTree(ll s, ll e, ll nd, ll idx, ll val)
{
    if(s > idx || e < idx) return;
    if(s == e) {
        tree[nd].set(val);
        return;
    }
    ll mid = (s + e) / 2;
    UpdateTree(s, mid, nd * 2, idx, val);
    UpdateTree(mid + 1, e, nd * 2 + 1, idx, val);
    tree[nd] = Calcu(tree[nd * 2], tree[nd * 2 + 1]);
}

Nd Getans(ll s, ll e, ll nd, ll l, ll r)
{
    if(s > r || l > e) return Nd();
    if(l <= s && e <= r) return tree[nd];
    ll mid = (s + e) / 2;
    return Calcu(Getans(s, mid, nd * 2, l, r), Getans(mid + 1, e, nd * 2 + 1, l, r));
}

int main()
{
    ll i, j;
    scanf("%lld", &n);
    for(i=1;i<=n;i++) scanf("%lld", &arr[i]);
    init(1, n, 1);
    ll Q;
    scanf("%lld", &Q);
    while(Q--) {
        ll q;
        scanf("%lld", &q);
        if(q == 1) {
            ll x, y;
            scanf("%lld %lld", &x, &y);
            UpdateTree(1, n, 1, x, y);
        }
        else {
            ll x, y;
            scanf("%lld %lld", &x, &y);
            Nd res = Getans(1, n, 1, x, y);
            printf("%lld\n", res.r - res.l);
        }
    }
    return 0;
}