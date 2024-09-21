#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int arr[100010];
int tree[400000];
int n, k;

void init(int st, int ed, int nd)
{
    if(st == ed) {
        tree[nd] = arr[st];
        return;
    }
    int mid = (st + ed) / 2;
    init(st, mid, nd * 2);
    init(mid + 1, ed, nd * 2 + 1);
    tree[nd] = tree[nd * 2] + tree[nd * 2 + 1];
}

void dele(int st, int ed, int nd, int idx)
{
    if(idx < st || ed < idx) return;
    if(st == ed) {
        tree[nd] = 0;
        return;
    }
    int mid = (st + ed) / 2;
    dele(st, mid, nd * 2, idx);
    dele(mid + 1, ed, nd * 2 + 1, idx);
    tree[nd] = tree[nd * 2] + tree[nd * 2 + 1];
}

int getsum(int st, int ed, int nd, int l, int r)
{
    if(st > r || l > ed) return 0;
    if(l <= st && ed <= r) return tree[nd];
    int mid = (st + ed) / 2;
    return getsum(st, mid, nd * 2, l, r) + getsum(mid + 1, ed, nd * 2 + 1, l, r);
}

int getidx(int st, int ed, int nd, int Rank)
{
    if(st == ed) return st;
    int mid = (st + ed) / 2;
    if(Rank <= tree[nd * 2]) return getidx(st, mid, nd * 2, Rank);
    else return getidx(mid + 1, ed, nd * 2 + 1, Rank - tree[nd * 2]);
}

int main()
{
    int i, j;
    scanf("%d %d", &n, &k);
    for(i=1;i<=n;i++) arr[i] = 1;
    init(1, n, 1);
    vector <int> ans;
    int nw = k;
    if(nw > n) {
        if(nw % n == 0) nw = n;
        else nw %= n;
    }
    while(1) {
        ans.push_back(nw);
        dele(1, n, 1, nw);
        int sum0 = 0;
        if(nw > 1) sum0 = getsum(1, n, 1, 1, nw - 1);
        int sum1 = getsum(1, n, 1, nw + 1, n);
        int sum2 = getsum(1, n, 1, 1, n);
        if(sum2 == 1 || sum2 == 0) {
            ans.push_back(getidx(1, n, 1, 1));
            break;
        }
        int now_idx = sum0 + k;
        if(k > sum1) {
            now_idx = k;
            now_idx -= sum1;
            if(now_idx > sum2) {
                if(now_idx % sum2 == 0) now_idx = sum2;
                else now_idx %= sum2;
            }
        }
        nw = getidx(1, n, 1, now_idx);
    }
    printf("<");
    for(i=0;i<n - 1;i++) printf("%d, ", ans[i]);
    printf("%d>", ans[i]);
    return 0;
}