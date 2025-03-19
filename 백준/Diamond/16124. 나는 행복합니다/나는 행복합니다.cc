#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static const ll Mod = 998244353;
static const int MAXN = 1000000;

ll Mod10[MAXN + 5];

struct Nd {
    int dig;       
    ll val[10];   
};

Nd seg[4 * MAXN];     
int mp[4 * MAXN][10]; 

string s;
int N, Q;

Nd Calcu(const Nd &L, const Nd &R) {
    Nd res;
    res.dig = L.dig + R.dig;
    for(int d = 0; d < 10; d++){
        ll tmp = (L.val[d] * Mod10[R.dig]) % Mod;
        tmp = (tmp + R.val[d]) % Mod;
        res.val[d] = tmp;
    }
    return res;
}

bool isIdentity(int node){
    for(int i=0;i<10;i++){
        if(mp[node][i] != i) return false;
    }
    return true;
}

void push(int idx, int st, int ed){
    if(isIdentity(idx)) return;
    ll tmp[10];
    memset(tmp, 0, sizeof(tmp));
    for(int i = 0; i < 10; i++){
        int to = mp[idx][i]; 
        tmp[to] = (tmp[to] + seg[idx].val[i]) % Mod;
    }
    for(int i = 0; i < 10; i++){
        seg[idx].val[i] = tmp[i];
    }
    if(st != ed){
        int lch = idx * 2, rch = idx * 2 + 1;
        for(int c : {lch, rch}){
            int newMp[10];
            for(int i=0; i<10; i++){
                newMp[i] = mp[idx][ mp[c][i] ];
            }
            for(int i=0; i<10; i++){
                mp[c][i] = newMp[i];
            }
        }
    }

    iota(mp[idx], mp[idx]+10, 0);
}

void init(int idx, int start, int end)
{
    iota(mp[idx], mp[idx]+10, 0);

    if(start == end) {
        int pos = start - 1;
        int digit = s[pos] - '0';
        
        seg[idx].dig = 1;
        memset(seg[idx].val, 0, sizeof(seg[idx].val));
        seg[idx].val[digit] = 1;
        return;
    }

    int mid = (start + end) >> 1;
    init(idx*2, start, mid);
    init(idx*2+1, mid+1, end);

    seg[idx] = Calcu(seg[idx*2], seg[idx*2+1]);
}


void UpdateRange(int idx, int st, int ed, int l, int r, int x, int y){
    push(idx, st, ed);

    if(r < st || ed < l) return;

    if(l <= st && ed <= r){
        mp[idx][x] = y;
        push(idx, st, ed);
        return;
    }

    int mid = (st + ed) >> 1;
    UpdateRange(idx*2,   st,   mid, l, r, x, y);
    UpdateRange(idx*2+1, mid+1, ed, l, r, x, y);

    seg[idx] = Calcu(seg[idx*2], seg[idx*2+1]);
}

Nd getRes(int idx, int st, int ed, int l, int r){

    push(idx, st, ed);

    if(r < st || ed < l){
        Nd ret;
        ret.dig = -1;
        memset(ret.val, 0, sizeof(ret.val));
        return ret;
    }
    if(l <= st && ed <= r){
        return seg[idx];
    }

    int mid = (st + ed) >> 1;
    Nd left = getRes(idx*2,   st,   mid, l, r);
    Nd right= getRes(idx*2+1, mid+1, ed, l, r);
    if(left.dig == -1) return right;
    if(right.dig== -1) return left;
    return Calcu(left, right);
}

ll Query(int l, int r){
    Nd ret = getRes(1, 1, N, l, r);
    ll ans = 0;

    for(int d=0; d<10; d++){
        ans = (ans + ret.val[d] * d) % Mod;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> s;
    N = (int)s.size();

    Mod10[0] = 1;
    for(int i=1; i<=N; i++){
        Mod10[i] = (Mod10[i-1] * 10) % Mod;
    }

    init(1, 1, N);

    cin >> Q;
    while(Q--){
        int t; cin >> t;
        if(t == 1){
            int l, r, x, y;
            cin >> l >> r >> x >> y;
            UpdateRange(1, 1, N, l, r, x, y);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << Query(l, r) << "\n";
        }
    }
    return 0;
}
