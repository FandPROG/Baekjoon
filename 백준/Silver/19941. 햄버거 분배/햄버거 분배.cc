#include <stdio.h>
#include <algorithm> 

int n, k;
char s[20010];

int main()
{
	int i, j;
	scanf("%d %d", &n, &k);
	scanf("%s", s);
	int ans = 0;
	for (i = 0; i < n; i++) {
		if (s[i] == 0) continue;
		if (s[i] == 'P') {
			for (j = 1; j <= k; j++) {
				if (i + j > n) break;
				if (s[i + j] == 'H') {
					ans++;
					s[i + j] = 0;
					break;
				}
			}
		}
		if (s[i] == 'H') {
			for (j = 1; j <= k; j++) {
				if (i + j > n) break;
				if (s[i + j] == 'P') {
					ans++;
					s[i + j] = 0;
					break;
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}