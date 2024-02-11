#include <stdio.h>
#include <string.h>

char s[110];

int main()
{
	int i, j;
	scanf("%s", s);
	int l = strlen(s), l2;
	if (l % 2 == 1) l2 = l / 2 + 1;
	else l2 = l / 2;
	int ch = 0;
	for (i = 0; i < l2; i++) {
		if (s[i] != s[l - i - 1]) ch = 1;
	}
	if (ch == 1) printf("0");
	else printf("1");
	return 0;
}