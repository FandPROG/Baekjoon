#include <stdio.h>

int n, m;
char sta[10010];
int l;

int main()
{
	int i, j;
	scanf("%d", &n);
	int cnt = 0;
	sta[cnt++] = 'I', sta[cnt++] = 'O', sta[cnt++] = 'I';
	for (i = 1; i < n; i++) {
		sta[cnt++] = 'O';
		sta[cnt++] = 'I';
	}
	scanf("%d", &l);
	char s[10010];
	int ans = 0;
	scanf("%s", s);
	for (j = 0; j < l - cnt + 1; j++) {
		int src = 0, ch = 0;
		for (int k = j; k < j + cnt; k++) {
			if (sta[src++] != s[k]) ch = 1;
		}
		if (ch == 0) ans++;
	}
	printf("%d", ans);
	return 0;
}