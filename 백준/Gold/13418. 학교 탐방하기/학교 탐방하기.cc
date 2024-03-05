#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int par[1010];

struct dat{
    int x, y, val;
};

bool comp(dat a, dat b)
{
    return a.val < b.val;
}

int ffind(int x)
{
    if(par[x] == x) return x;
    else return par[x] = ffind(par[x]);
}

void funion(int x, int y)
{
    int a = ffind(x);
    int b = ffind(y);
    if(a < b) par[b] = a;
    else par[a] = b;
    return;
}

vector <dat> vec;

int main()
{
    int i, j;
    scanf("%d %d", &n, &m);
    m++;
    for(i=0;i<m;i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        vec.push_back({x, y, z});
    }
    for(i=1;i<=n;i++) par[i] = i;
    sort(vec.begin(), vec.end(), comp);
//    for(i=0;i<m;i++) printf("%d %d %d\n", vec[i].x, vec[i].y, vec[i].val);
    int ansL = 0, ansS = 0;
    for(i=0;i<m;i++) {
        int x = vec[i].x, y = vec[i].y;
        if(ffind(x) == ffind(y)) continue;
        funion(x, y);
        if(vec[i].val == 0) ansL++;
    }
    for(i=0;i<=n;i++) par[i] = i;
    for(i=0;i<m;i++) {
        int val = vec[i].val;
        if(val == 1) vec[i].val = 0;
        else vec[i].val = 1;
    }
    sort(vec.begin(), vec.end(), comp);
//    for(i=0;i<m;i++) printf("%d %d %d\n", vec[i].x, vec[i].y, vec[i].val);
    for(i=0;i<m;i++) {
        int x = vec[i].x, y = vec[i].y;
        if(ffind(x) == ffind(y)) continue;
        funion(x, y);
        if(vec[i].val == 1) ansS++;
    }
    printf("%d", (ansL * ansL) - (ansS * ansS));
    return 0;
}