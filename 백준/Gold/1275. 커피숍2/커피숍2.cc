#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

long long n, m;
long long arr[100010];
long long segtree[400010];

long long init(long long s, long long e, long long node) {
	if (s == e) return segtree[node] = arr[s];
	long long mid = (s + e) / 2;
	return segtree[node] = init(s, mid, node * 2) + init(mid + 1, e, node * 2 + 1);
}

long long sum(long long s, long long e, long long low, long long high, long long node)
{
	if (e < low || s > high) return 0;
	if (low <= s && high >= e) return segtree[node];
	long long mid = (s + e) / 2;
	return sum(s, mid, low, high, node * 2) + sum(mid + 1, e, low, high, node * 2 + 1);
}

void update(long long s, long long e, long long node, long long idx, long long dis)
{
	if (idx < s || idx > e) return;
	segtree[node] += dis;
	if (s != e) {
		long long mid = (s + e) / 2;
		update(s, mid, node * 2, idx, dis);
		update(mid + 1, e, node * 2 + 1, idx, dis);
	}
}

int main()
{
	long long i, j;
	scanf("%lld %lld", &n, &m);
	for (i = 1; i <= n; i++) scanf("%lld", &arr[i]);
	init(1, n, 1);
	for (i = 0; i < m; i++) {
		int x, y, a, b;
		scanf("%lld %lld %lld %lld", &x, &y, &a, &b);
		long long mx = max(x, y), mn = min(x, y);
		printf("%lld\n", sum(1, n, mn, mx, 1));
		long long dis = b - arr[a];
		update(1, n, 1, a, dis);
		arr[a] = b;
	}
	return 0;
}