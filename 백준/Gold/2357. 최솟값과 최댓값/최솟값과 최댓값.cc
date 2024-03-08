#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int arr[100010];
int Ltree[400010], Mtree[400010];

int Linit(int s, int e, int node)
{
	if (s == e) return Ltree[node] = arr[s];
	int mid = (s + e) / 2;
	return Ltree[node] = min(Linit(s, mid, node * 2), Linit(mid + 1, e, node * 2 + 1));
}

int Lfind(int s, int e, int node, int low, int high)
{
	if (low > e || s > high) return 2e9;
	if (low <= s && e <= high) return Ltree[node];
	int mid = (s + e) / 2;
	return min(Lfind(s, mid, node * 2, low, high), Lfind(mid + 1, e, node * 2 + 1, low, high));
}

int Minit(int s, int e, int node)
{
	if (s == e) return Mtree[node] = arr[s];
	int mid = (s + e) / 2;
	return Mtree[node] = max(Minit(s, mid, node * 2), Minit(mid + 1, e, node * 2 + 1));
}

int Mfind(int s, int e, int node, int low, int high)
{
	if (low > e || s > high) return 0;
	if (low <= s && e <= high) return Mtree[node];
	int mid = (s + e) / 2;
	return max(Mfind(s, mid, node * 2, low, high), Mfind(mid + 1, e, node * 2 + 1, low, high));
}

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) scanf("%d", &arr[i]);
	Minit(1, n, 1);
	Linit(1, n, 1);
	for (j = 0; j < m; j++) {
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%d %d\n", Lfind(1, n, 1, x, y), Mfind(1, n, 1, x, y));
	}
	return 0;
}