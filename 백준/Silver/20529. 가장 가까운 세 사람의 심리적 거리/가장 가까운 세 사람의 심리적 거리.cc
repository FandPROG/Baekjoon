#include <stdio.h>

int t, n;
char s[100010][5];

int main()
{
	int i, j, k;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%d", &n);
		for (j = 0; j < n; j++) {
			scanf("%s", s[j]);
		}
		if (n > 32) printf("0\n");
		else {
			int mn = 2e9;
			for (j = 0; j < n - 2; j++) {
				for (k = j + 1; k < n - 1; k++) {
					for (int l = k + 1; l < n; l++) {
						int ans = 0;
						for (int m = 0; m < 4; m++) {
							if (s[j][m] == s[k][m] && s[j][m] != s[l][m]) ans += 2;
							else if (s[j][m] != s[k][m] && s[k][m] == s[l][m]) ans += 2;
							else if (s[j][m] == s[k][m] && s[k][m] == s[l][m]) ans += 0;
							else ans += 2;
						}
						if (ans < mn) mn = ans;
					}
				}
			}
			printf("%d\n", mn);
		}
	}
	return 0;
}