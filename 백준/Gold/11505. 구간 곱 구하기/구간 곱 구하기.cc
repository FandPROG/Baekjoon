#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

long long n, m, k;
long long arr[1000010];
long long segtree[4000010];

long long init(long long s, long long e, long long node)
{
	if (s == e) return segtree[node] = arr[s];
	long long mid = (s + e) / 2;
	return segtree[node] = (init(s, mid, node * 2) * init(mid + 1, e, node * 2 + 1)) % 1000000007;
}

long long multi(long long s, long long e, long long low, long long high, long long node)
{
	if (e < low || high < s) return 1;
	if (low <= s && e <= high) return segtree[node];
	long long mid = (s + e) / 2;
	return (multi(s, mid, low, high, node * 2) * multi(mid + 1, e, low, high, node * 2 + 1)) % 1000000007;
}

long long edit(long long s, long long e, long long node, long long idx, long long dis) {
	if (idx > e || idx < s) return segtree[node];
	if (s == e) return segtree[node] = dis;
	long long mid = (s + e) / 2;
	return segtree[node] = (edit(s, mid, node * 2, idx, dis) * edit(mid + 1, e, node * 2 + 1, idx, dis)) % 1000000007;
}

int main()
{
	long long i, j;
	scanf("%lld %lld %lld", &n, &m, &k);
	for (i = 1; i <= n; i++) scanf("%lld", &arr[i]);
	init(1, n, 1);
	for (i = 0; i < k + m; i++) {
		long long Q, x, y;
		scanf("%lld %lld %lld", &Q, &x, &y);
		if (Q == 1) {
			edit(1, n, 1, x, y);
			arr[x] = y;
		}
		else {
			long long mx = max(x, y), mn = min(x, y);
			printf("%lld\n", multi(1, n, mn, mx, 1));
		}
	}
	return 0;
}