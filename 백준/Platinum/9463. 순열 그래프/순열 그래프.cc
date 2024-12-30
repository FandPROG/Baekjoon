#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int tree[400010];

void init(int s, int e, int nd)
{
    if(s == e) {
        tree[nd] = 0;
        return;
    }
    int mid = (s + e) / 2;
    init(s, mid, nd * 2);
    init(mid + 1, e, nd * 2 + 1);
    tree[nd] = 0;
}

void Update(int s, int e, int nd, int idx, int val)
{
    if(idx < s || idx > e) return;
    if(s == e) {
        tree[nd] += val;
        return;
    }
    int mid = (s + e) / 2;
    Update(s, mid, nd * 2, idx, val);
    Update(mid + 1, e, nd * 2 + 1, idx, val);
    tree[nd] = tree[nd * 2] + tree[nd * 2 + 1];
}

int GetSum(int s, int e, int nd, int l, int r)
{
    if(l > e || r < s) return 0;
    if(l <= s && e <= r) return tree[nd];
    int mid = (s + e) / 2;
    return GetSum(s, mid, nd * 2, l, r) + GetSum(mid +1 , e, nd * 2 + 1, l, r);
}

int main()
{
    int i, j;
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        vector <int> a;
        vector <pair<int, int>> b;
        vector <int> val, idx;
        for(i=1;i<=n;i++) {
            int x;
            scanf("%d", &x);
            a.push_back(x);
        }
        for(i=0;i<n;i++) {
            int x;
            scanf("%d", &x);
            b.push_back({x, i});
        }
        sort(b.begin(), b.end());
        for(i=0;i<n;i++) {
            val.push_back(b[i].first);
            idx.push_back(b[i].second);
        }
        long long ans = 0;
        for(i=0;i<n;i++) {
            int ret = lower_bound(val.begin(), val.end(), a[i]) - val.begin();
            int anidx = idx[ret] + 1;
            //printf("idx : %d\n", anidx);
            Update(1, n, 1, anidx, +1);
            ans += (long long)GetSum(1, n, 1, anidx + 1, n);
        }
        printf("%lld\n", ans);
        init(1, n, 1);
    }
    return 0;
}