#include <bits/stdc++.h>

using namespace std;

const int MAX = 100010;

struct dat{
    int in, out, idx;
};

bool comp(dat a, dat b) {
    if(a.in == b.in) return a.out < b.out;
    else return a.in < b.in;
}

vector <int> vec[MAX];
int seg[MAX * 4], lzy[MAX * 4];
dat arr[MAX];
int timer = 1;

void dfs(int u) {
    arr[u].in = timer++;
    for(auto v : vec[u]) {
        dfs(v);
    }
    arr[u].out = timer - 1;
}

void init(int st, int ed, int nd) {
    if(st == ed) {
        seg[nd] = 1;
        return;
    }
    int mid = (st + ed) / 2;
    init(st, mid, nd * 2);
    init(mid + 1, ed, nd * 2 + 1);
    seg[nd] = seg[nd * 2] + seg[nd * 2 + 1];
}

void push(int st, int ed, int nd) {
    if(lzy[nd] != -1) {
        seg[nd] = (ed - st + 1) * lzy[nd];
        if(st != ed) {
            lzy[nd * 2] = lzy[nd];
            lzy[nd * 2 + 1] = lzy[nd];
        }
    }
    lzy[nd] = -1;
}

void Update(int st, int ed, int nd, int l, int r, int val) {
    push(st, ed, nd);
    if(r < arr[st].in || l > arr[ed].in) return;
    if(l <= arr[st].in && arr[ed].in <= r) {
        lzy[nd] = val;
        push(st, ed, nd);
        return;
    }
    int mid = (st + ed) / 2;
    Update(st, mid, nd * 2, l, r, val);
    Update(mid + 1, ed, nd * 2 + 1, l, r, val);
    seg[nd] = seg[nd * 2] + seg[nd * 2 + 1];
}

int SegSum(int st, int ed, int nd, int l, int r) {
    push(st, ed, nd);
    if(r < arr[st].in || l > arr[ed].in) return 0;
    if(l <= arr[st].in && arr[ed].in <= r) return seg[nd];
    int mid = (st + ed) / 2;
    return SegSum(st, mid, nd * 2, l, r) + SegSum(mid + 1, ed, nd * 2 + 1, l, r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, Q;
    cin >> n;
    for(int i=0;i<=n * 4;i++) lzy[i] = -1;
    for(int i=1;i<=n;i++) {
        int x;
        cin >> x;
        arr[i].idx = i;
        if(x != 0) vec[x].push_back(i);
    }
    dfs(1);
    sort(arr + 1, arr + 1 + n, comp);
    init(1, n, 1);
    vector <int> mp(n + 1);
    for(int i=1;i<=n;i++) {
        mp[arr[i].idx] = i;
    }
    cin >> Q;
    while(Q--) {
        int q, i;
        cin >> q >> i;
        if(q == 1) {
            Update(1, n, 1, arr[mp[i]].in + 1, arr[mp[i]].out, 1);
        }
        else if(q == 2) {
            Update(1, n, 1, arr[mp[i]].in + 1, arr[mp[i]].out, 0);
        }
        else {
            cout << SegSum(1, n, 1, arr[mp[i]].in + 1, arr[mp[i]].out) << "\n";
        }
    }
    return 0;
}