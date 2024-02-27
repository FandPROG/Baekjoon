#include <stdio.h>

int map[1010][1010];

int main()
{
	int i, j;
	int C, R, K;
	scanf("%d %d %d", &C, &R, &K);
	int cnt = 1;
	int x = 1, y = 1;
	int now_cnt = 0, now_dis = 1, dis = 1;
	if (C * R < K) {
		printf("0");
		return 0;
	}
	while (1) {
		if (K <= cnt) break;
		if (dis == 1) {
			map[x][y++] = cnt++;
			now_cnt++;
			if (now_cnt >= R - now_dis) {
				dis = 2;
				now_cnt = 0;
			}
		}
		else if (dis == 2) {
			map[x++][y] = cnt++;
			now_cnt++;
			if (now_cnt >= C - now_dis) {
				dis = 3;
				now_cnt = 0;
			}
		}
		else if (dis == 3) {
			map[x][y--] = cnt++;
			now_cnt++;
			if (now_cnt >= R - now_dis) {
				dis = 4;
				now_cnt = 0;
			}
		}
		else if (dis == 4) {
			map[x--][y] = cnt++;
			now_cnt++;
			if (now_cnt >= C - now_dis) {
				x++;
				y++;
				dis = 1;
				now_dis += 2;
				now_cnt = 0;
			}
		}
	}
	printf("%d %d", x, y);
	return 0;
}