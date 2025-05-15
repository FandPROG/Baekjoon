#include <bits/stdc++.h>

using namespace std;
const int MAX =  100000;

struct dat{
    int fir, in, out;
};

vector <dat> arr;
vector <int> vec[MAX + 1];
vector <int> euler, deep;
int seg[MAX * 8], timer = 1;

void dfs(int u, int par, int d) {
    arr[u].in = timer++;
    arr[u].fir = euler.size();
    euler.push_back(u);
    deep.push_back(d);
    for(auto v : vec[u]) {
        if (v == par) continue;
        dfs(v, u, d + 1);
        euler.push_back(u);
        deep.push_back(d);
    }
    arr[u].out = timer - 1;
}

void init(int st, int ed, int nd) {
    if(st == ed) {
        seg[nd] = st;
        return;
    }
    int mid = (st + ed) / 2;
    init(st, mid, nd * 2);
    init(mid + 1, ed, nd * 2 + 1);
    seg[nd] = (deep[seg[nd * 2]] > deep[seg[nd * 2 + 1]] ? seg[nd * 2 + 1] : seg[nd * 2]);
}

int getQuery(int st, int ed, int nd, int l, int r) {
    if(l > ed || r < st) return -1;
    if(l <= st && ed <= r) return seg[nd];
    int mid = (st + ed) / 2;
    int LQ = getQuery(st, mid, nd *2, l, r);
    int RQ = getQuery(mid + 1, ed, nd * 2 + 1, l, r);
    if(LQ == -1) return RQ;
    if(RQ == -1) return LQ;
    return deep[LQ] < deep[RQ] ? LQ : RQ;
}

int getLCA(int a, int b) 
{
    int l = arr[a].fir, r = arr[b].fir;
    if(l > r) swap(l, r);
    int idx = getQuery(1, deep.size(), 1, l, r);
    return euler[idx];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    arr.resize(n + 1);
    for(int i=1;i<n;i++) {
        int x, y;
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    deep.push_back(0);
    euler.push_back(0);
    dfs(1, -1, 0);
    init(1, deep.size(), 1);
    int Q;
    cin >> Q;
    while(Q--) {
        int x, y;
        cin >> x >> y;
        cout << getLCA(x, y) << '\n';
    }
    return 0;
}