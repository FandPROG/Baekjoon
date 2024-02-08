#include <stdio.h>
#include <algorithm>

int n, m;
char s[1000010];

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	scanf("%s", s);
	int cnt = 0, ans = 0;
	for (i = 0; i < m;) {
		if (s[i] == 'I' && s[i + 1] == 'O' && s[i + 2] == 'I') i += 2, cnt++;
		else {
			if ((cnt - n + 1) > 0) ans += (cnt - n + 1);
			cnt = 0;
			i++;
		}
	}
	printf("%d", ans);
	return 0;
}