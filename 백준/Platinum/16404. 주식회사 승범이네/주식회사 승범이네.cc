#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct dat {
    ll in, out, idx;
};

vector <ll> vec[100000];
vector <dat> arr;
ll tree[400000], lazy[400000];
ll timer = 1;

bool comp(dat x, dat y) {
    if(x.in == y.in) return x.out < y.out;
    else return x.in < y.in;
}


void dfs(ll u) {
    arr[u].in = timer++;
    for(ll v : vec[u]) {
        dfs(v);
    }
    arr[u].out = timer - 1;
}

void init(ll st, ll ed, ll nd) {
    if(st == ed) {
        tree[nd] = 0;
        return;
    }
    ll mid = (st + ed) / 2;
    init(st, mid, nd * 2);
    init(mid + 1, ed, nd * 2 + 1);
    tree[nd] = tree[nd * 2] + tree[nd * 2 + 1];
}

void push(ll st, ll ed, ll nd) {
    if(lazy[nd] != 0) {
        tree[nd] += (ed - st + 1) * lazy[nd];
        if(st != ed) {
            lazy[nd * 2] += lazy[nd];
            lazy[nd * 2 + 1] += lazy[nd];
        }
        lazy[nd] = 0;
    }
}

void UpdateRange(ll st, ll ed, ll nd, ll l, ll r, ll val) {
    if(arr[st].in > r || l > arr[ed].in) return;
    if(l <= arr[st].in && arr[ed].in <= r) {
        lazy[nd] += val;
        push(st, ed, nd);
        return;
    }
    ll mid = (st + ed) / 2;
    UpdateRange(st, mid, nd * 2, l, r, val);
    UpdateRange(mid + 1, ed, nd * 2 + 1, l, r, val);
    tree[nd] = tree[nd * 2] + tree[nd * 2 + 1];
}

int getSum(ll st, ll ed, ll nd, ll l, ll r) {
    push(st, ed, nd);
    if(arr[st].in > r || l > arr[ed].in) return 0;
    if(l <= arr[st].in && arr[ed].in <= r) return tree[nd];
    ll mid = (st + ed) / 2;
    return getSum(st, mid, nd * 2, l, r) + getSum(mid + 1, ed, nd * 2 + 1, l, r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin.tie(0);
    ll i, j;
    ll n, m;
    cin >> n >> m;
    arr.resize(n + 1);
    for(i=1;i<=n;i++) {
        ll x;
        cin >> x;
        if(x != -1) vec[x].push_back(i);
    }
    dfs(1);
    for(i=1;i<=n;i++) arr[i].idx = i;
    sort(arr.begin() + 1, arr.end(), comp);
    vector <ll> ans(n + 1);
    for(i = 1;i<=n;i++) {
        ans[arr[i].idx] = i;
    }
    while(m--) {
        ll q, idx;
        cin >> q >> idx;
        if(q == 1) {
            ll val;
            cin >> val;
            UpdateRange(1, n, 1, arr[ans[idx]].in, arr[ans[idx]].out, val);
        }
        else {
            cout << getSum(1, n, 1, ans[idx], ans[idx]) << '\n';
        }
    }
    return 0;
}