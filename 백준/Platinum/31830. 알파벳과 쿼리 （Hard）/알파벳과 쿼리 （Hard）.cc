#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using lD = long double;
using D = double;

struct Nd {
    int Fidx, Lidx;
    int AlpBundle;
};

Nd Calcu(Nd left, Nd right) {
    Nd res;
    res.AlpBundle = left.AlpBundle + right.AlpBundle;
    if(left.Lidx == right.Fidx) res.AlpBundle--;
    res.Lidx = right.Lidx;
    res.Fidx = left.Fidx;
    return res;
}

Nd tree[800010];
int lazy[800010];
string S;

void apply(int idx, int shift) {
    lazy[idx] = (lazy[idx] + shift) % 26;
    tree[idx].Fidx = (tree[idx].Fidx + shift) % 26;
    tree[idx].Lidx = (tree[idx].Lidx + shift) % 26;
}

void push(int idx) {
    if(lazy[idx]) {
        apply(idx * 2, lazy[idx]);
        apply(idx * 2 + 1, lazy[idx]);
        lazy[idx] = 0;
    }
}

void init(int st, int ed, int nd) {
    if(st == ed) {
        int idx = st;
        tree[nd] = {S[idx] - 'A', S[idx] - 'A', 1};
        return;
    }
    int mid = (st + ed) / 2;
    init(st, mid, nd * 2);
    init(mid + 1, ed, nd * 2  + 1);
    tree[nd] = Calcu(tree[nd * 2], tree[nd * 2 + 1]);
}

Nd getRes(int st, int ed, int nd, int l, int r)
{
    if(ed < l || r < st) return {-1, -1, 0};
    if(l <= st && ed <= r) return tree[nd];
    push(nd);
    int mid = (st + ed) / 2;
    Nd left = getRes(st, mid, nd * 2, l, r);
    Nd right = getRes(mid + 1, ed, nd * 2 + 1, l, r);
    if(left.Fidx == -1) return right;
    else if(right.Fidx == -1) return left;
    else return Calcu(left, right);
}

void Update(int st, int ed, int nd, int l, int r)
{
    if(ed < l || r < st) return;
    if(l <= st && ed <= r) {
        apply(nd, 1);
        return;
    }
    push(nd);
    int mid = (st + ed) / 2;
    Update(st, mid, nd * 2, l, r);
    Update(mid + 1, ed, nd * 2 + 1, l, r);
    tree[nd] = Calcu(tree[nd * 2], tree[nd * 2 + 1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, j;
    int N, Q;
    cin >> N >> Q;
    string ss;
    cin >> ss;
    S = ' ' + ss;
    init(1, N, 1);
    while(Q--) {
        int Query;
        int l, r;
        cin >> Query >> l >> r;
        if(Query == 1) cout << getRes(1, N, 1, l, r).AlpBundle << "\n";
        else Update(1, N, 1, l, r);
    }
    return 0;
}