#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[100010];
int tree[400010];

void init(int st, int ed, int nd)
{
    if(st == ed) {
        tree[nd] = st;
        return;
    }
    int mid = (st + ed) / 2;
    init(st, mid, nd * 2);
    init(mid + 1, ed, nd * 2 + 1);
    tree[nd] = (arr[tree[nd * 2]] <= arr[tree[nd * 2 + 1]]) ? tree[nd * 2] : tree[nd * 2 + 1];
}

int getMinimum(int st, int ed, int nd, int l, int r)
{
    if(st > r || l > ed) return 0;
    if(l <= st && ed <= r) return tree[nd];
    int mid = (st + ed) / 2;
    int res1 = getMinimum(st, mid, nd * 2, l, r);
    int res2 = getMinimum(mid + 1, ed, nd * 2 + 1, l, r);
    return (arr[res1] <= arr[res2]) ? res1 : res2;
}

void Update(int st, int ed, int nd, int idx, int val)
{
    if(idx < st || ed < idx) return;
    if(st == ed) {
        arr[tree[nd]] = val;
        return;
    }
    int mid = (st + ed) / 2;
    Update(st, mid, nd * 2, idx, val);
    Update(mid + 1, ed, nd * 2 + 1, idx, val);
    tree[nd] = (arr[tree[nd * 2]] <= arr[tree[nd * 2 + 1]]) ? tree[nd * 2] : tree[nd * 2 + 1];  
}

int main()
{
    int i, j;
    scanf("%d", &n);
    for(i=1;i<=n;i++) scanf("%d", &arr[i]);
    arr[0] = 2e9;
    int Q;
    init(1, n, 1);
    scanf("%d", &Q);
    while(Q--) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        if(x == 1) Update(1, n, 1, y, z);
        if(x == 2) {
            printf("%d\n", getMinimum(1, n, 1, y, z));
        }
    }
    return 0;
}