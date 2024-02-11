#include <stdio.h>
#include <string.h>

char s[20];
int ans;

int main() 
{
	int i;
	scanf("%s", s);
	for (i = 0; i < strlen(s); i++) {
		int n = s[i] - 'A' + 1;
		if (n < 16) {
			if (n % 3 == 0) n /= 3;
			else n = (n / 3) + 1;
			ans += (2 + n);
		}
		else {
			n -= 15;
			if (1 <= n && n <= 4) ans += 8;
			else if (5 <= n && n <= 7) ans += 9;
			else ans += 10;
		}
	}
	printf("%d", ans);
	return 0;
}