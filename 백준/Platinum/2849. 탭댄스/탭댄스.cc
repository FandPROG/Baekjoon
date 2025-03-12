#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using lD = long double;
using D = double;

struct Nd{
    int score;
    int Lmx, Rmx;
    int len;
    //int isAlt;
    char L, R;
};

Nd Calcu(Nd left, Nd right) {
    Nd res;
    res.L = left.L, res.R = right.R;
    res.len = left.len + right.len;
    res.Lmx = left.Lmx;
    res.Rmx = right.Rmx;
    if(left.Lmx == left.len && left.R != right.L) res.Lmx = max(res.Lmx, left.score + right.Lmx);
    if(right.Rmx == right.len && left.R != right.L) res.Rmx = max(res.Rmx, right.score + left.Rmx);
    res.score = max(right.score, left.score);
    if(left.R != right.L) res.score = max(res.score, left.Rmx + right.Lmx);
    return res;
}

Nd tree[800010];

void init(int st, int ed, int nd) {
    if(st == ed) {
        tree[nd] = {1, 1, 1, 1, 'L', 'L'};
        return;
    }
    int mid = (st + ed) / 2;
    init(st, mid, nd * 2);
    init(mid + 1, ed, nd * 2 + 1);
    tree[nd] = Calcu(tree[nd * 2], tree[nd * 2 + 1]);
}

void Update(int st, int ed, int nd, int idx) {
    if(idx > ed || idx < st) return;
    if(st == ed) {
        if(tree[nd].L == 'L') tree[nd] = {1, 1, 1, 1, 'R', 'R'};
        else tree[nd] = {1, 1, 1, 1, 'L', 'L'};
        return;
    }
    int mid = (st + ed) / 2;
    Update(st, mid, nd * 2, idx);
    Update(mid + 1, ed, nd * 2 + 1, idx);
    tree[nd] = Calcu(tree[nd * 2], tree[nd * 2 + 1]);
}

Nd gerRes(int st, int ed, int nd, int l, int r)
{
    if(ed < l || r < st) return {0, 0, 0, 0, 's', 's'};
    if(l <= st && ed <= r) return tree[nd];
    int mid = (st + ed) / 2;
    Nd Lres = gerRes(st, mid, nd * 2, l, r);
    Nd Rres = gerRes(mid + 1, ed, nd * 2 + 1, l, r);
    if(Lres.L == 's') return Rres;
    else if(Rres.R == 's') return Lres;
    else return Calcu(Lres, Rres);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, j;
    int N, Q;
    cin >> N >> Q;
    init(1, N, 1);
    while(Q--) {
        int x;
        cin >> x;
        Update(1, N, 1, x);
        cout << gerRes(1, N, 1, 1, N).score << '\n';
    }
    return 0;
}