#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int m;
int par[2010];

struct dat{
    int x, y, val;
};

bool comp(dat a, dat b)
{
    return a.val < b.val;
}

int ffind(int x)
{
    if(x == par[x]) return x;
    else return par[x] = ffind(par[x]);
}

void funion(int x, int y)
{
    int a = ffind(par[x]);
    int b = ffind(par[y]);
    if(a < b) par[b] = a;
    else par[a] = b;
}

int main()
{
    int i, j;
    int s;
    scanf("%d %d %d", &n, &m, &s);
    for(i=0;i<=n;i++) par[i] = i;
    vector <dat> vec;
    for(i=0;i<m;i++) {
        int x, y, val;
        scanf("%d %d %d", &x, &y, &val);
        vec.push_back({x, y, val});
    }
    sort(vec.begin(), vec.end(), comp);
    int ans = 0;
    for(i=0;i<m;i++) {
        int a = vec[i].x, b = vec[i].y;
        if(ffind(a) == ffind(b)) continue;
        funion(a, b);
        ans += vec[i].val;
    }
    int x;
    for(i=0;i<n;i++) scanf("%d", &x);
    printf("%d", ans);
    return 0;
}