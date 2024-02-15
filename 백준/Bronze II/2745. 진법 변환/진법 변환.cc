#include <stdio.h>
#include <math.h>
#include <string.h>

char s[110];
int m, l;

int main()
{
	int i, j;
	scanf("%s %d", s, &m);
	l = strlen(s);
	int ans = 0, cnt = 0;
	for (i = l - 1; i >= 0; i--) {
		if ('0' <= s[i] && s[i] <= '9') {
			ans += (s[i] - '0') * pow(m, cnt++);
		}
		else {
			ans += (10 + (s[i] - 'A')) * pow(m, cnt++);
		}
	}
	printf("%d", ans);
	return 0;
}