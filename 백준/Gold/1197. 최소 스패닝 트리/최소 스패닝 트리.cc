#include <stdio.h>
#include <algorithm>

int n, m, s[100010];

struct ig
{
	int c, a, b;
};

bool compare(ig x, ig y)
{
	return x.c < y.c;
}


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
	int i, j, ans = 0;
	struct ig ign[100010];
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		s[i] = i;
	}
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &ign[i].a, &ign[i].b, &ign[i].c);
	}
	std::sort(ign, ign + m, compare);
	for (i = 0; i < m; i++) {
		if (ffind(ign[i].a) != ffind(ign[i].b)) {
			funion(ign[i].b, ign[i].a);
			ans += ign[i].c;
		}
	}
	printf("%d", ans);
	return 0;
}