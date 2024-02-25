#include <stdio.h>
#include <cmath>

int n;
int cnt[45];

int main()
{
	int i, j;
	int mx = -2e9;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (x > mx) mx = x;
		cnt[x]++;
	}
	int ans = 0, ct = 0;
	for (i = 0; i <= mx; i++) {
		if (cnt[i] > 2) {
			printf("0");
			return 0;
		}
		else if (i > 0 && cnt[i] > cnt[i - 1]) {
			printf("0");
			return 0;
		}
		else {
			if (cnt[i] == 2) ans++;
			else if (cnt[i] == 1) ct = 1;
		}
	}
	ans += ct;
	int res = pow(2, ans);
	printf("%d", res);
	return 0;
}