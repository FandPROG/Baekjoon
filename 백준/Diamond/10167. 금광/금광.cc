#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using lD = long double;
using D = double;

struct Nd {
    ll lmx, rmx, mx;
    ll sum;
};

struct dat{
    ll x, y, w;
};

int n;
Nd tree[24000];

vector <dat> vec;
vector <ll> imx, imy;

bool comp(dat a, dat b) {
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

void ResetTree() {
    for(int i=0;i<=n*4;i++) {
        tree[i] = {0, 0, 0, 0};
    }
}

Nd Calcu(Nd left, Nd right)
{
    Nd res;
    res.sum = right.sum + left.sum;
    res.lmx = max(left.lmx, left.sum + right.lmx);
    res.rmx = max(right.rmx, right.sum + left.rmx);
    res.mx = max(left.rmx + right.lmx, max(left.mx, max(res.sum, right.mx)));
    return res;
}

void Update(int st, int ed, int nd, int idx, ll val) {
    if(st > idx || idx > ed) return;
    if(st == ed) {
        tree[nd].sum += val;
        tree[nd].lmx += val;
        tree[nd].rmx += val;
        tree[nd].mx  += val;
        return;
    }
    int mid = (st + ed) / 2;
    Update(st, mid, nd * 2 + 1, idx, val);
    Update(mid + 1, ed, nd * 2 + 2, idx, val);
    tree[nd] = Calcu(tree[nd * 2 + 1], tree[nd * 2 + 2]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, j;
    cin >> n;
    vec.resize(n);
    for(i=0;i<n;i++) {
        cin >> vec[i].x >> vec[i].y >> vec[i].w;
        imx.push_back(vec[i].x);
        imy.push_back(vec[i].y);
    }
    sort(imx.begin(), imx.end()), sort(imy.begin(), imy.end());
    imx.erase(unique(imx.begin(), imx.end()), imx.end());
    imy.erase(unique(imy.begin(), imy.end()), imy.end());

    for(auto &ix : vec) {
        ix.x = lower_bound(imx.begin(), imx.end(), ix.x) - imx.begin();
        ix.y = lower_bound(imy.begin(), imy.end(), ix.y) - imy.begin();
        swap(ix.x, ix.y);
    }
    sort(vec.begin(), vec.end(), comp);

    ll res = 0;

    for(int i=0;i<n;i++) {
        if(i && vec[i - 1].x == vec[i].x) continue;
        ResetTree();
        for(int j=i;j<n;j++) {
            Update(0, imx.size() - 1, 0, vec[j].y, vec[j].w);
            if(j == n-1 || vec[j].x != vec[j + 1].x) res = max(res, tree[0].mx);
        }
    }
    cout << res;
    return 0;
}