#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int n;
ll H[1000010];
ll tree[4000010];

void init(int st, int ed, int nd)
{
    if(st == ed) {
        tree[nd] = st;
        return;
    }
    int mid = (st + ed) / 2;
    init(st, mid, nd * 2);
    init(mid + 1, ed, nd * 2 + 1);
    if(H[tree[nd * 2 + 1]] > H[tree[nd * 2]])
        tree[nd] = tree[nd * 2];
    else
        tree[nd] = tree[nd * 2 + 1];
}

int getMinimumIndex(int st, int ed, int nd, int l, int r) {
    if(r < st || ed < l) return 0;
    if(l <= st && ed <= r) return tree[nd];
    int mid = (st + ed) / 2;
    int idx1 = getMinimumIndex(st, mid, nd * 2, l, r);
    int idx2 = getMinimumIndex(mid + 1, ed, nd * 2 + 1, l, r);
    return (H[idx1] < H[idx2]) ? idx1 : idx2;
}

ll getAns(int st, int ed)
{
    int MinimumIndex = getMinimumIndex(1, n, 1, st, ed);
    ll res = H[MinimumIndex] * (ed - st + 1);
    if(MinimumIndex > st) {
        res = max(getAns(st, MinimumIndex - 1), res);
    }
    if(MinimumIndex < ed) {
        res = max(getAns(MinimumIndex + 1, ed), res);
    }
    return res;
}

int main()
{
    int i, j;
    scanf("%d", &n);
    for(i=1;i<=n;i++) scanf("%lld", &H[i]);
    H[0] = 2e9;
    init(1, n, 1);
    printf("%lld", getAns(1, n));
    return 0;
}