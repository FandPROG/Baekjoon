#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int tree[2000000];

void Update(int st, int ed, int nd, int idx, int val)
{
    if(idx < st || idx > ed) return;
    if(st == ed) {
        tree[nd] += val;
        return;
    }
    int mid = (st + ed) / 2;
    Update(st, mid, nd * 2, idx, val);
    Update(mid + 1, ed, nd * 2 + 1, idx, val);
    tree[nd] = tree[nd * 2] + tree[nd * 2 + 1];
}

int getValue(int st, int ed, int nd, int Rank)
{
    if(st == ed) return st;
    int mid = (st + ed) / 2;
    if(tree[nd * 2] >= Rank) return getValue(st, mid, nd * 2, Rank);
    else return getValue(mid + 1, ed, nd * 2 + 1, Rank - tree[nd * 2]);
}

int main()
{
    int i, j;
    int n, Q;
    scanf("%d", &n);
    for(i=1;i<=n;i++) {
        int x;
        scanf("%d", &x);
        Update(1, n, 1, i, x);
    }
    scanf("%d", &Q);
    while(Q--) {
        int type;
        scanf("%d", &type);
        if(type == 1) {
            int x, y;
            scanf("%d %d", &x, &y);
            Update(1, n, 1, x, y);
        }
        else {
            int x;
            scanf("%d", &x);
            printf("%d\n", getValue(1, n, 1, x));
        }
    }
    return 0;
}