#include <stdio.h>

int main()
{
	int h, m, s = 0;
	int wm, ws;
	scanf("%d:%d", &h, &m);
	wm = h, ws = m;
	if (m < wm) h--, m = (m + 60) - wm;
	else m -= wm;
	if (s < ws) {
		m--, s = 60 - ws;
		if (m < 0) {
			h--;
			m += 60;
		}
	}
	if (10 > h) printf("0%d", h);
	else printf("%d", h);
	printf(":");
	if (10 > m) printf("0%d", m);
	else printf("%d", m);
	printf(":");
	if (10 > s) printf("0%d", s);
	else printf("%d", s);
	return 0;
}