#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, k;
int time[2][500010];

int main()
{
	int i, j;
	scanf("%d %d", &n, &k);
	for (i = 0; i < 2; i++) {
		for (j = 0; j <= 500000; j++) {
			time[i][j] = -1;
		}
	}
	queue <pair<int, int>> q;
	q.push({ n, 0 });
	while (!q.empty()) {
		int loc = q.front().first, val = q.front().second;
		q.pop();
		if (loc < 0 || loc > 500000) continue;
		if (time[val % 2][loc] == -1) {
			time[val % 2][loc] = val;
			q.push({ loc + 1, val + 1 });
			q.push({ loc - 1, val + 1 });
			q.push({ loc * 2, val + 1 });
		}
	}
	int now_time = 0, t = k;
	while (1) {
		if (t + now_time > 500000) break;
		t += now_time;
		if (time[now_time % 2][t] <= now_time && time[now_time % 2][t] != -1) {
			printf("%d", now_time);
			return 0;
		}
		now_time++;
	}
	printf("-1");
	return 0;
}