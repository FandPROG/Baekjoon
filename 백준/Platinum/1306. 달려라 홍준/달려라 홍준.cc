#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, m, arr[1000010];
int segtree[4000010];

int init(int s, int e, int node)
{
    if(s == e) return segtree[node] = arr[s];
    int mid = (s+e)/2;
    return segtree[node] = max(init(s, mid, node*2), init(mid+1, e, node*2+1));
}

int mxfind(int s, int e, int low, int high, int node)
{
    if(low > e || high < s) return 0;
    if(low <= s && e <= high) return segtree[node];
    long long mid = (s + e)/2;
    return max(mxfind(s, mid, low, high, node*2), mxfind(mid + 1, e, low, high, node*2+1));
}

int main()
{
    int i, j;
    scanf("%d %d", &n, &m);
    for(i=1;i<=n;i++) scanf("%d", &arr[i]);
    init(1, n, 1);
    for(i=m;i<=n-m+1;i++) {
        int low = i - m + 1;
        int high = i + m - 1;
        printf("%d\n", mxfind(1, n, low, high, 1));
    }
    return 0;
}