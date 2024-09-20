#include <stdio.h>
#include <algorithm>

using namespace std;

const int inf = 2e9;
const int minus_inf = -2e9;

struct node
{
    int mx, mn;
};

int n;
int arr[100010];
node tree[400000];

void init(int st, int ed, int nd)
{
    if(st == ed) {
        tree[nd].mn = arr[st];
        tree[nd].mx = arr[st];
        return;
    }
    int mid = (st + ed) / 2;
    init(st, mid, nd * 2);
    init(mid + 1, ed, nd * 2 + 1);
    tree[nd].mx = max(tree[nd * 2].mx, tree[nd * 2 + 1].mx);
    tree[nd].mn = min(tree[nd * 2].mn, tree[nd * 2 + 1].mn);
}

void updt(int st, int ed, int nd, int idx, int val)
{
    if(st > idx || idx > ed) return;
    if(st == ed) {
        tree[nd].mx = val;
        tree[nd].mn = val;
        return;
    }
    int mid = (st + ed) / 2;
    updt(st, mid, nd * 2, idx, val);
    updt(mid + 1, ed, nd * 2 + 1, idx, val);
    tree[nd].mx = max(tree[nd * 2].mx, tree[nd * 2 + 1].mx);
    tree[nd].mn = min(tree[nd * 2].mn, tree[nd * 2 + 1].mn);
}

node getval(int st, int ed, int nd, int l, int r) {
    if(l > ed || st > r) return {minus_inf, inf};
    if(l <= st && ed <= r) return tree[nd];
    int mid = (st + ed) / 2;
    node res1 = getval(st, mid, nd * 2, l, r);
    node res2 = getval(mid + 1, ed, nd * 2 + 1, l, r);
    node res;
    res.mx = max(res1.mx, res2.mx);
    res.mn = min(res1.mn, res2.mn);
    return res;
}

void treeprint(int st, int ed, int nd)
{
    if(st == ed) {
        printf("%d ", tree[nd]);
        return;
    }
    int mid = (st + ed) / 2;
    treeprint(st, mid, nd * 2);
    treeprint(mid + 1, ed, nd * 2 + 1);
}

int main()
{
    int i, j;
    int t;
    scanf("%d", &t);
    while(t--) {
        int Q;
        scanf("%d %d", &n, &Q);
        for(i=1;i<=n;i++) arr[i] = i;
        init(1, n, 1);
        while(Q--) {
            int type;
            scanf("%d", &type);
            if(type == 0) {
                int x, y;
                scanf("%d %d", &x, &y);
                x++, y++;
                swap(arr[x], arr[y]);
                updt(1, n, 1, x, arr[x]);
                updt(1, n, 1, y, arr[y]);
            }
            else {
                int x, y;
                scanf("%d %d", &x, &y);
                x++, y++;
                node ans = getval(1, n, 1, x, y);
                //printf("ans : %d %d\n", ans.mn, ans.mx);
                if(ans.mx > y) printf("NO\n");
                else if(ans.mn < x) printf("NO\n");
                else printf("YES\n");
            }
            //treeprint(1, n, 1);
            //printf("\n지금:\n");
        }
        //printf("\n-----------------------------------\n");
    }
    return 0;
}