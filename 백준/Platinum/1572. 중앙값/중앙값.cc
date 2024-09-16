#include <stdio.h>
#include <algorithm>

using namespace std;
using ll = long long;

int n, k;
int tree[270000];
int arr[250000];

void rebuildTree(int st, int ed, int nd, int idx, int val)
{
    if(ed < idx || idx < st) return;
    if(st == ed) {
        tree[nd] += val;
        return;
    }
    int mid = (st + ed) / 2;
    rebuildTree(st, mid, nd * 2, idx, val);
    rebuildTree(mid + 1, ed , nd * 2 + 1, idx, val);
    tree[nd] = tree[nd * 2] + tree[nd * 2 + 1];
}

int get_value(int st, int ed, int nd, int fd) {
    if(st == ed) return st;
    int mid = (st + ed) / 2;
    if(tree[nd * 2] >= fd) return get_value(st, mid, nd * 2, fd);
    else return get_value(mid + 1, ed, nd * 2 + 1, fd - tree[nd * 2]);
}

int main()
{
    int i, j;
    scanf("%d %d", &n, &k);
    int mn = 2e9, mx = -2e9;
    for(i=0;i<n;i++) {
        scanf("%d", &arr[i]);
        mn = min(mn, arr[i]);
        mx = max(mx, arr[i]);
    }
    for(i=0;i<k;i++) {
        rebuildTree(mn, mx, 1, arr[i], +1);
    }
    ll ans = 0;
    ans += get_value(mn, mx, 1, (k + 1) / 2);
    for(i=k;i<n;i++) {
        rebuildTree(mn, mx, 1, arr[i], +1);
        rebuildTree(mn, mx, 1, arr[i - k], -1);
        int res = get_value(mn, mx, 1, (k + 1) / 2);
        ans += res;
    }
    printf("%lld", ans);
    return 0;
}