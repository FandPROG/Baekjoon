#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int par[510], ch[510];
int n, m;

int ffind(int x)
{
    if(x == -1) return -1;
    if(x == par[x]) return x;
    else return par[x] = ffind(par[x]);
}

void funion(int x, int y)
{
    int a = ffind(x), b = ffind(y);
    if(a < b) par[b] = a;
    else par[a] = b;
    return;
}

int main()
{
    int i, j;
    int tc = 0;
    while(1) {
        tc++;
        scanf("%d %d", &n, &m);
        if(n == 0 && m == 0) break;
        for(i=1;i<=n;i++) par[i] = i;
        for(i=0;i<m;i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            int fx = ffind(x), fy = ffind(y);
            if(fx == fy) {
                par[fx] = -1;
            }
            funion(x, y);
        }
        int ans = 0;
        for(i=1;i<=n;i++) {
            int fx = ffind(i);
            if(fx == -1) continue;
            if(ch[fx] == 0) ch[fx] = 1, ans++;
        }
        if(ans > 1) printf("Case %d: A forest of %d trees.\n", tc, ans);
        else if(ans == 1) printf("Case %d: There is one tree.\n", tc);
        else if(ans == 0) printf("Case %d: No trees.\n", tc);
        for(i=0;i<=n;i++) ch[i] = 0;
    }
    return 0;
}