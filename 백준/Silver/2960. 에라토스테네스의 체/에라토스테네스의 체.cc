#include <stdio.h>

int prime[1010];
int n, k;

int main()
{
	int i, j;
	scanf("%d %d", &n, &k);
	int cnt = 0;
	for (i = 2; i <= n; i++) {
		if (prime[i] == 1) continue;
		cnt++;
		if (cnt == k) {
			printf("%d", i);
			return 0;
		}
		for (j = i * 2; j <= n; j += i) {
			if (prime[j] == 1) continue;
			prime[j] = 1;
			cnt++;
			if (cnt == k) {
				printf("%d", j);
				return 0;
			}
		}
	}
	return 0;
}