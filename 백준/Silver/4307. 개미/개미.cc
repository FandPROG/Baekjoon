#include <stdio.h>
#include <algorithm>

using namespace std;

int L, n;

int main()
{
	int i, t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &L, &n);
		int mx = -2e9, mn = -2e9;
		for (i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			mn = max(mn, min(x, L - x));
			mx = max(mx, max(x, L - x));
		}
		printf("%d %d\n", mn, mx);
	}
	return 0;
}