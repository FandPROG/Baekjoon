#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

long long n, m;
long long arr[1000010];
long long segtree[4000010];

long long init(long long s, long long e, long long node) {
	if (s == e) return segtree[node] = arr[s];
	long long mid = (s + e) / 2;
	return segtree[node] = init(s, mid, node * 2) + init(mid + 1, e, node * 2 + 1);
}

long long sum(long long s, long long e, long long low, long long high, long long node) {
	if (low > e || s > high) return 0;
	if (low <= s && e <= high) return segtree[node];
	long long mid = (s + e) / 2;
	return sum(s, mid, low, high, node * 2) + sum(mid + 1, e, low, high, node * 2 + 1);
}

void update(long long s, long long e, long long node, long long idx, long long dis) {
	if (idx < s || idx > e) return;
	segtree[node] += dis;
	long long mid = (s + e) / 2;
	if (s != e) {
		update(s, mid, node * 2, idx, dis);
		update(mid + 1, e, node * 2 + 1, idx, dis);
	}
}

int main()
{
	long long i, j;
	scanf("%lld %lld", &n, &m);
	for (i = 1; i <= n; i++) arr[i] = 0;
	init(1, n, 1);
	for (i = 0; i < m; i++) {
		long long a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		if (a == 0) {
			long long mx = max(b, c), mn = min(b, c);
			printf("%lld\n", sum(1, n, mn, mx, 1));
		}
		else if (a == 1) {
			long long dis = c - arr[b];
			update(1, n, 1, b, dis);
			arr[b] = c;
		}
	}
	return 0;
}