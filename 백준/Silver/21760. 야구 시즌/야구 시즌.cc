#include <stdio.h>
#include <cmath>

using namespace std;

int n, m, k;
long long d;

int main()
{
	int i, j;
	int t;
	scanf("%d", &t);
	while (t--) {
		long long mn = 2e15, ans;
		scanf("%d %d %d %lld", &n, &m, &k, &d);
		for (i = 1;; i++) {
			long long s = n * m;
			long long res = ((s * (s - m) * i) + (s * (m - 1) * k * i)) / 2;
			if (res > d) break;
			if (mn > d - res) {
				mn = d - res;
				ans = res;
			}
		}
		if (ans > d) printf("-1\n");
		else printf("%d\n", ans);
	}
}