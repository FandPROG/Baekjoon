#include <stdio.h>

int n;

int main()
{
	int i;
	scanf("%d", &n);
	int ans = 7;
	int alp = 'J';
	for (i = 0; i < n - 1; i++) {
		alp++;
		ans++;
		if (alp > 'L') alp = 'A';
		if (ans > 9) ans = 0;
	}
	printf("%c%d", alp, ans);
}