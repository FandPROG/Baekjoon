#include <stdio.h>
#include <algorithm>

using namespace std;
using ll = long long;

ll tree[4000010];

void ReloadTree(int st, int ed, int nd, int idx, ll val)
{
    if(idx < st || ed < idx) return;
    if(st == ed) {
        tree[nd] += val;
        return;
    }
    int mid = (st + ed) / 2;
    ReloadTree(st, mid, nd * 2, idx, val);
    ReloadTree(mid + 1, ed, nd * 2 + 1, idx, val);
    tree[nd] = tree[nd * 2] + tree[nd * 2 + 1];
}

int getCandyCount(int st, int ed, int nd, int Rank)
{
    if(st == ed) return st;
    int mid = (st + ed) / 2;
    if(Rank <= tree[nd * 2]) return getCandyCount(st, mid, nd * 2, Rank);
    else return getCandyCount(mid + 1, ed, nd * 2 + 1, Rank - tree[nd * 2]);
}

int main()
{
    int i, j;
    int Q;
    scanf("%d", &Q);
    int mn = 1;
    int mx = 1000000;
    while(Q--) {
        int type;
        scanf("%d", &type);
        if(type == 1) {
            int x;
            scanf("%d", &x);
            int res = getCandyCount(mn, mx, 1, x);
            printf("%d\n", res);
            ReloadTree(mn, mx, 1, res, -1);
        }
        else {
            int x;
            ll y;
            scanf("%d %lld", &x, &y);
            ReloadTree(mn, mx, 1, x, y);
        }
    }
    return 0;
}