#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

ll inf = (ll)1e9 * (ll)1e9 + 7;

struct st {
    ll LtoM; // 왼쪽에서 중간으로 최대
    ll MtoR; // 중간에서 오른쪽으로 최대
    ll mn;   // 구간 내 최소값
    ll mx;   // 구간 내 최대값
    ll ans;  // 전체 구간에서의 최적값

    st() {
        LtoM = MtoR = -inf;
        mn = inf;
        mx = -inf;
        ans = -inf;
    }

    void set(ll x) {
        LtoM = MtoR = -inf;
        mn = mx = x;
        ans = -inf;
    }

    const st operator+(const st &K) {
        st R;
        R.LtoM = max({LtoM, K.LtoM, K.mx - mn});
        R.MtoR = max({MtoR, K.MtoR, mx - K.mn});
        R.mx = max(mx, K.mx);
        R.mn = min(mn, K.mn);
        R.ans = max({ans, K.ans, K.MtoR - mn, LtoM - K.mn});
        return R;
    }
};

int n;
ll arr[353333];
st tree[1533333];

void init(int s, int e, int nd) {
    if (s == e) {
        tree[nd].set(arr[s]);
        return;
    }
    int mid = (s + e) / 2;
    init(s, mid, nd * 2);
    init(mid + 1, e, nd * 2 + 1);
    tree[nd] = tree[nd * 2] + tree[nd * 2 + 1];
}

void Update(int s, int e, int nd, int idx, ll val) {
    if (idx < s || idx > e) return;
    if (s == e) {
        tree[nd].set(val);
        return;
    }
    int mid = (s + e) / 2;
    Update(s, mid, nd * 2, idx, val);
    Update(mid + 1, e, nd * 2 + 1, idx, val);
    tree[nd] = tree[nd * 2] + tree[nd * 2 + 1];
}

st getans(int s, int e, int nd, int l, int r) {
    if (l > e || s > r) return st();
    if (l <= s && e <= r) return tree[nd];
    int mid = (s + e) / 2;
    return getans(s, mid, nd * 2, l, r) + getans(mid + 1, e, nd * 2 + 1, l, r);
}

int main() {
    int Q;
    scanf("%d %d", &n, &Q);
    for (int i = 1; i <= n; i++) scanf("%lld", &arr[i]);
    init(1, n, 1);
    while (Q--) {
        int x;
        scanf("%d", &x);
        if (x == 1) {
            int idx;
            ll val;
            scanf("%d %lld", &idx, &val);
            Update(1, n, 1, idx, val);
        } else {
            int l, r;
            scanf("%d %d", &l, &r);
            st res = getans(1, n, 1, l, r);
            printf("%lld\n", res.ans);
        }
    }
    return 0;
}
