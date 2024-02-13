#include <stdio.h>

int n, m, s[1000010];

int ffind(int x)
{
	if (x == s[x]) return x;
	return s[x] = ffind(s[x]);
}

void funion(int x, int y)
{
	int a, b;
	a = ffind(x);
	b = ffind(y);
	if (a > b) s[a] = b;
	else s[b] = a;
}

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) s[i] = i;
	for (i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0) funion(b, c);
		else if (a == 1) {
			if (ffind(b) == ffind(c)) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}