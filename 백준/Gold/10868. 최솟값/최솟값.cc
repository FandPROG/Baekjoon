#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int arr[100010], segtree[400010];

int init(int s, int e, int node)
{
	if (s == e) return segtree[node] = arr[s];
	int mid = (s + e) / 2;
	return segtree[node] = min(init(s, mid, node * 2), init(mid + 1, e, node * 2 + 1));
}

int segfind(int s, int e, int low, int high, int node)
{
	if (e < low || s > high) return 2e9;
	if (low <= s && e <= high) return segtree[node];
	int mid = (s + e) / 2;
	return min(segfind(s, mid, low, high, node * 2), segfind(mid + 1, e, low, high, node * 2 + 1));
}

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) scanf("%d", &arr[i]);
	init(1, n, 1);
	for (i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%d\n", segfind(1, n, x, y, 1));
	}
	return 0;
}