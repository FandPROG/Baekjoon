#include <stdio.h>
#include <math.h>

int n;

int main()
{
	scanf("%d", &n);
	if (n == 1) {
        printf("1/1");
        return 0;
    }
	int x = 1, y = 1;
	int all_cnt = 1;
	int n_cnt = 1;
	int cnt = 1;
	while (1)
	{
		if (n_cnt >= all_cnt) {
			if (all_cnt % 2 == 0) x++;
			else y++;
			all_cnt++;
			n_cnt = 1;
			cnt++;
		}
		else {
			if (all_cnt % 2 == 0) x++, y--;
			else x--, y++;
			n_cnt++;
			cnt++;
		}
		if (cnt >= n) {
			printf("%d/%d", x, y);
			return 0;
		}
	}
	return 0;
}