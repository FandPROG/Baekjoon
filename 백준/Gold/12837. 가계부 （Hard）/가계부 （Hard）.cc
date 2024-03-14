#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

long long n, Q;
long long segtree[4000010];

long long sum(long long s, long long e, long long low, long long high, long long node) {
    if(e < low || high < s) return 0;
    if(low <= s && e <= high) return segtree[node];
    long long mid = (s + e)/2;
    return sum(s, mid, low, high, node*2) + sum(mid + 1, e, low, high, node*2+1);
}

void edit(long long s, long long e, long long idx, long long node, long long dis)
{
    if(idx < s || idx > e) return;
    segtree[node] += dis;
    if(s != e) {
        long long mid = (s + e) / 2;
        edit(s, mid, idx, node*2, dis);
        edit(mid+1, e, idx, node*2+1, dis);
    }
}

int main()
{
    long long i, j;
    scanf("%lld %lld", &n, &Q);
    for(i=0;i<Q;i++) {
        long long x, y, z;
        scanf("%lld %lld %lld", &x, &y, &z);
        if(x == 1) edit(1, n, y, 1, z);
        else if(x == 2) printf("%lld\n", sum(1, n, y, z, 1));
    }
}