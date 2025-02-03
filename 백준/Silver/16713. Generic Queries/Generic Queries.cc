#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using lD = long double;
using D = double;

int tree[4000010];
int arr[1000010];

void init(int st, int ed, int nd)
{
    if(st == ed) {
        tree[nd] = arr[st];
        return;
    }
    int mid = (st + ed) / 2;
    init(st, mid, nd * 2);
    init(mid + 1, ed, nd * 2 + 1);
    tree[nd] = tree[nd * 2] ^ tree[nd * 2 + 1];
}

int getans(int st, int ed, int nd, int l, int r) {
    if(l > ed || r < st) return 0;
    if(l <= st && ed <= r) return tree[nd];
    int mid = (st + ed) / 2;
    return getans(st, mid, nd * 2, l, r) ^ getans(mid + 1, ed, nd * 2 + 1, l, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int i, j;
    int N, Q;
    cin >> N >> Q;
    for(i=1;i<=N;i++) cin >> arr[i];
    init(1, N, 1);
    int ans = 0;
    while(Q--) {
        int l, r;
        cin >> l >> r;
        ans ^= getans(1, N, 1, l, r);
    }
    cout << ans;
    return 0;
}