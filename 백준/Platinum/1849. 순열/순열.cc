#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int arr[100010];
int tree[400000];
int ans[100010];

void init(int st, int ed, int nd)
{
    if(st == ed) {
        tree[nd] = 1;
        return;
    }
    int mid = (st + ed) / 2;
    init(st, mid, nd * 2);
    init(mid + 1, ed, nd * 2 + 1);
    tree[nd] = tree[nd * 2] + tree[nd * 2 + 1];
}

void fillidx(int st, int ed, int nd, int idx)
{
    if(idx < st || idx > ed) return;
    if(st == ed) {
        tree[nd] = 0;
        return;
    }
    int mid = (st + ed) / 2;
    fillidx(st, mid, nd * 2, idx);
    fillidx(mid + 1, ed, nd * 2 + 1, idx);
    tree[nd] = tree[nd * 2] + tree[nd * 2 + 1];
}

int findidx(int st, int ed, int nd, int Rank)
{
    if(st == ed) return st;
    int mid = (st + ed) / 2;
    if(Rank < tree[nd * 2]) return findidx(st, mid, nd * 2, Rank);
    else return findidx(mid + 1, ed, nd * 2 + 1, Rank - tree[nd * 2]);
}

int main()
{
    int i, j;
    scanf("%d", &n);
    for(i=1;i<=n;i++) scanf("%d", &arr[i]);
    init(1, n, 1);
    for(i=1;i<=n;i++) {
        int rank = arr[i];
        int idx = findidx(1, n, 1, rank);
        ans[idx] = i;
        fillidx(1, n, 1, idx);
    }
    for(i=1;i<=n;i++) printf("%d\n", ans[i]);
    return 0;
}