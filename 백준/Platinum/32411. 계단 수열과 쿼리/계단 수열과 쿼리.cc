#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 100005;

int N, Q;
int a[MAXN];
int d[MAXN];

struct Node {
    int len, lcnt, rcnt, mcnt;
};

Node combine(Node left, Node right) {
    if(left.len == 0) return right;
    if(right.len == 0) return left;
    Node res;
    res.len = left.len + right.len;
    res.lcnt = (left.lcnt == left.len ? left.len + right.lcnt : left.lcnt);
    res.rcnt = (right.rcnt == right.len ? right.len + left.rcnt : right.rcnt);
    res.mcnt = max({left.mcnt, right.mcnt, left.rcnt + right.lcnt});
    return res;
}

const int SEG_SIZE = 4 * MAXN;

Node seg[11][SEG_SIZE];

int n_d;

void build(int k, int idx, int l, int r) {
    if(l == r) {
        int valid = (abs(d[l]) == k);
        seg[k][idx] = {1, valid, valid, valid};
        return;
    }
    int mid = (l + r) / 2;
    build(k, idx*2, l, mid);
    build(k, idx*2+1, mid+1, r);
    seg[k][idx] = combine(seg[k][idx*2], seg[k][idx*2+1]);
}

void updateTree(int k, int idx, int l, int r, int pos, int val) {
    if(pos < l || pos > r) return;
    if(l == r) {
        seg[k][idx] = {1, val, val, val};
        return;
    }
    int mid = (l + r) / 2;
    if(pos <= mid) updateTree(k, idx*2, l, mid, pos, val);
    else updateTree(k, idx*2+1, mid+1, r, pos, val);
    seg[k][idx] = combine(seg[k][idx*2], seg[k][idx*2+1]);
}

Node queryTree(int k, int idx, int l, int r, int ql, int qr) {
    if(qr < l || r < ql) return {0, 0, 0, 0};
    if(ql <= l && r <= qr) return seg[k][idx];
    int mid = (l + r) / 2;
    Node leftNode = queryTree(k, idx*2, l, mid, ql, qr);
    Node rightNode = queryTree(k, idx*2+1, mid+1, r, ql, qr);
    return combine(leftNode, rightNode);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> Q;
    for(int i = 1; i <= N; i++){
        cin >> a[i];
    }
    
    n_d = (N - 1);
    for(int i = 1; i <= n_d; i++){
        d[i] = a[i+1] - a[i];
    }
    
    for(int k = 1; k <= 10; k++){
        if(n_d > 0) build(k, 1, 1, n_d);
    }
    while(Q--){
        int type;
        cin >> type;
        if(type == 1){
            int l, r, x;
            cin >> l >> r >> x;
            if(l > 1 && n_d > 0){
                d[l-1] += x;
                for(int k = 1; k <= 10; k++){
                    int valid = (abs(d[l-1]) == k);
                    updateTree(k, 1, 1, n_d, l-1, valid);
                }
            }
            if(r < N && n_d > 0){
                d[r] -= x;
                for(int k = 1; k <= 10; k++){
                    int valid = (abs(d[r]) == k);
                    updateTree(k, 1, 1, n_d, r, valid);
                }
            }
        }
        else if(type == 2){
            int l, r, k;
            cin >> l >> r >> k;
            if(l == r){
                cout << 1 << "\n";
                continue;
            }
            Node res = queryTree(k, 1, 1, n_d, l, r-1);
            cout << res.mcnt + 1 << "\n";
        }
    }
    return 0;
}
