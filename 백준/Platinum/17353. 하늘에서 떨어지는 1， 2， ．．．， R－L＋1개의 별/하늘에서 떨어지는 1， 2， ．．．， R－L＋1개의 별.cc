#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

ll n;
ll arr[100010];
ll tree[400010];
pair<ll, ll> lazy[400010]; //첫째항, 공차

void push(ll l, ll r, ll nd) {
    if (lazy[nd].first != 0 || lazy[nd].second != 0) {
        ll len = r - l + 1;
        tree[nd] += (len * (2 * lazy[nd].first + (len - 1) * lazy[nd].second)) / 2;
        if (l != r) {
            ll mid = (l + r) / 2;
            lazy[nd * 2].first += lazy[nd].first;
            lazy[nd * 2].second += lazy[nd].second;
            lazy[nd * 2 + 1].first += lazy[nd].first + (mid - l + 1) * lazy[nd].second;
            lazy[nd * 2 + 1].second += lazy[nd].second;
        }
        lazy[nd] = {0, 0};
    }
}

void init(ll st, ll ed, ll nd)
{
    if(st == ed) {
        tree[nd] = arr[st];
        return;
    }
    ll mid = (st + ed) / 2;
    init(st, mid, nd * 2);
    init(mid + 1, ed, nd * 2 + 1);
    tree[nd] = tree[nd * 2] + tree[nd * 2 + 1];
}

ll sum(ll st, ll ed, ll nd, ll l, ll r)
{
    push(st, ed, nd);
    if(ed < l || st > r) return 0;
    if(l <= st && ed <= r) return tree[nd];
    ll mid = (st + ed) / 2;
    return sum(st, mid, nd * 2, l, r) + sum(mid + 1, ed, nd * 2 + 1, l, r);
}

void Update_range(ll st, ll ed, ll nd, ll l, ll r) {
    push(st, ed, nd);
    if (ed < l || st > r) return;
    if (l <= st && ed <= r) {
        lazy[nd].first += 1 + (st - l);
        lazy[nd].second += 1;
        push(st, ed, nd);
        return;
    }
    ll mid = (st + ed) / 2;
    Update_range(st, mid, nd * 2, l, r);
    Update_range(mid + 1, ed, nd * 2 + 1, l, r);
    tree[nd] = tree[nd * 2] + tree[nd * 2 + 1];
}


int main()
{
    ll i, j;
    scanf("%lld", &n);
    for(i=1;i<=n;i++) scanf("%lld", &arr[i]);
    init(1, n, 1);
    int Q;
    scanf("%d", &Q);
    while(Q--) {
        int type;
        scanf("%d", &type);
        if(type == 1) {
            ll L, R;
            scanf("%lld %lld", &L, &R);
            Update_range(1, n, 1, L, R);
        }
        else {
            ll x;
            scanf("%lld", &x);
            printf("%lld\n", sum(1, n, 1, x, x));
        }
    }
    return 0;
}