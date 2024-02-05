#include <stdio.h>

int x[11], y[11];

int main()
{
	int i;
	char now_win = 0;
	int x_sum = 0, y_sum = 0;
	for (i = 0; i < 10; i++) scanf("%d", &x[i]);
	for (i = 0; i < 10; i++) scanf("%d", &y[i]);
	for (i = 0; i < 10; i++) {
		if (x[i] > y[i]) x_sum += 3, now_win = 'A';
		else if (x[i] < y[i]) y_sum += 3, now_win = 'B';
		else {
			x_sum++;
			y_sum++;
		}
	}
	printf("%d %d\n", x_sum, y_sum);
	if (x_sum > y_sum) printf("A");
	else if (x_sum < y_sum) printf("B");
	else {
		if (now_win == 'A' || now_win == 'B') printf("%c ", now_win);
		else printf("D");
	}
	return 0;
}