#include <stdio.h>

int n;

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (x == 0) {
			printf("YES\n0");
			return 0;
		}
		else if (x == 1) {
			printf("YES\n1");
			return 0;
		}
		else {
			printf("YES\n%d", x * 111);
			return 0;
		}
	}
	return 0;
}