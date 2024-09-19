#include <stdio.h>
#include <algorithm>

using ll = long long;
using namespace std;

int arr[100010];
int tree[400000];
int n;

void init(int st, int ed, int nd)
{
    if(st == ed) {
        tree[nd] = st;
        return;
    }
    int mid = (st + ed) / 2;
    init(st, mid, nd * 2);
    init(mid + 1, ed, nd * 2 + 1);
    if(arr[tree[nd * 2]] > arr[tree[nd * 2 + 1]]) tree[nd] = tree[nd * 2 + 1];
    else tree[nd] = tree[nd * 2];
}

int get_minimum_idx(int st, int ed, int nd, int l, int r)
{
    if(st > r || ed < l) return -1;
    if(l <= st && ed <= r) return tree[nd];
    int mid = (st + ed) / 2;
    int res1 = get_minimum_idx(st, mid, nd * 2, l, r);
    int res2 = get_minimum_idx(mid + 1, ed, nd * 2 + 1, l, r);
    if(res1 == -1) return res2;
    if(res2 == -1) return res1;
    if(arr[res1] < arr[res2]) return res1;
    else return res2;
}

ll get_ans(int st, int ed)
{
    int minidx = get_minimum_idx(1, n, 1, st, ed);
    ll res = (ll)arr[minidx] * (ll)(ed - st + 1);
    if(st <= minidx - 1) {
        res = max(res, get_ans(st, minidx - 1));
    }
    if(ed >= minidx + 1) {
        res = max(res, get_ans(minidx + 1, ed));
    }
    return res;
}

int main()
{
    int i, j;
    while(1) {
        scanf("%d", &n);
        if(n == 0) return 0;
        for(i=1;i<=n;i++) scanf("%d", &arr[i]);
        init(1, n, 1);
        ll ans = get_ans(1, n);
        printf("%lld\n", ans);
    }
}