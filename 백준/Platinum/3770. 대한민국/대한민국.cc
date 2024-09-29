#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int n, m, k;
ll tree[4000];

struct par{
    int x, y;
};

bool comp(par a, par b)
{
    if(a.x == b.x) return a.y < b.y;
    else return a.x < b.x;
}

ll getSum(int st, int ed, int nd, int l, int r)
{
    if(ed < l || r < st) return 0;
    if(l <= st && ed <= r) return tree[nd];
    int mid = (st + ed) / 2;
    return getSum(st, mid, nd * 2, l, r) + getSum(mid + 1, ed, nd * 2 + 1, l, r);
}

void Update(int st, int ed, int nd, int idx, ll val)
{
    if(idx < st || ed < idx) return;
    if(st == ed) {
        tree[nd] += val;
        return;
    }
    int mid = (st + ed) / 2;
    Update(st, mid, nd * 2, idx, val);
    Update(mid + 1, ed, nd * 2 + 1, idx, val);
    tree[nd] = tree[nd * 2] + tree[nd * 2 + 1];
}

int main()
{
    //freopen("h.in", "r", stdin);
    //freopen("h.out", "w", stdout);

    int t;
    scanf("%d", &t);
    int level = 0;
    while(t--) {
        ll ans = 0;
        vector <par> vec;
        int i, j;
        level++;
        scanf("%d %d %d", &n, &m, &k);
        
        for(i=0;i<k;i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            vec.push_back({x, y});
        }
        sort(vec.begin(), vec.end(), comp);
        for(i=0;i<k;i++) {
            int idx = vec[i].y;
            ll res = 0;
            if(idx < m) res = getSum(1, m, 1, idx + 1, m);
            Update(1, m, 1, idx, +1);
            ans += res;
        }
        for(i=1;i<=m * 4;i++) tree[i] = 0;
        printf("Test case %d: %lld\n", level, ans);
        vec.clear();
    }
    
    //fclose(stdin);
    //fclose(stdout);

    return 0;
}