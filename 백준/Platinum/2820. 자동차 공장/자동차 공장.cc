#include <bits/stdc++.h>

using namespace std;

struct Euiler{
    int in, out, val, idx;
};

bool comp(Euiler a, Euiler b) {
    if(a.in == b.in) return a.out < b.out;
    else return a.in < b.in;
}

vector <int> vec[500010];
int tree[2000010], lazy[2000010];
vector <Euiler> arr;
int timer = 1;

void dfs(int u)
{
    arr[u].in = timer++;
    for(auto v : vec[u]) {
        dfs(v);
    }
    arr[u].out = timer - 1;
}

void push(int st, int ed, int nd) {
    if(lazy[nd] != 0) {
        tree[nd] += (ed - st + 1) * lazy[nd];
        if(st != ed) {
            lazy[nd * 2] += lazy[nd];
            lazy[nd * 2 + 1] += lazy[nd];
        }
    }
    lazy[nd] = 0;
}

void init(int st, int ed, int nd) {
    if(st == ed) {
        tree[nd] = arr[st].val;
        return;
    }
    int mid = (st + ed) / 2;
    init(st, mid, nd * 2);
    init(mid+1, ed, nd * 2 + 1);
    tree[nd] = tree[nd * 2] + tree[nd * 2 + 1];
}

int getSum(int st, int ed, int nd, int l, int r) {
    push(st, ed, nd);
    if(arr[st].in > r || l > arr[ed].in) return 0;
    if(l <= arr[st].in && arr[ed].in <= r) return tree[nd];
    int mid = (st + ed) / 2;
    return getSum(st, mid, nd * 2, l, r) + getSum(mid + 1, ed, nd * 2 + 1, l, r);
}

void Update(int st, int ed, int nd, int l, int r, int val) {
    if(arr[st].in > r || l > arr[ed].in) return;
    if (l <= arr[st].in && arr[ed].in <= r) {
        lazy[nd] += val;
        push(st, ed, nd);
        return;
    }
    int mid = (st + ed) / 2;
    Update(st, mid, nd * 2, l, r, val);
    Update(mid +1, ed, nd * 2 + 1, l, r, val);
    tree[nd] = tree[nd * 2] + tree[nd * 2 + 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, Q;
    cin >> n >> Q;
    arr.resize(n + 1);
    for(int i=1;i<=n;i++) {
        int x, y;
        cin >> x;
        arr[i].val = x;
        if(i > 1) {
            cin >> y;
            vec[y].push_back(i);
        }
    }
    dfs(1);
    for(int i=1;i<=n;i++) arr[i].idx = i;
    sort(arr.begin() + 1, arr.end(), comp);
    vector <int> pos(n + 1);
    for(int i=1;i<=n;i++) {
        pos[arr[i].idx] = i;
    }
    init(1, n, 1);
    while(Q--) {
        char q;
        cin >> q;
        if(q == 'p') {
            int x, y;
            cin >> x >> y;
            Update(1, n, 1, arr[pos[x]].in + 1, arr[pos[x]].out, y);
        }
        else {
            int x;
            cin >> x;
            cout << getSum(1, n, 1, pos[x], pos[x]) << "\n";
        }
    }
    return 0;
}