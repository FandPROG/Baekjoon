#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int rk[510];
vector<int> ans;
int ent[510], arr[510][510];
bool che[510];
int check = 0; //0이면 가능, 1이면 ?, 2면, impossible


int main()
{
	int i, j;
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 1; i <= n; i++) scanf("%d", &rk[i]);
		for (i = 1; i < n; i++) {
			for (j = i + 1; j <= n; j++) {
				arr[rk[j]][rk[i]] = 1;
				ent[rk[i]]++;
			}
		}
		scanf("%d", &m);
		for (i = 0; i < m; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			if (arr[x][y] == 1) {
				arr[x][y] = 0;
				arr[y][x] = 1;
				ent[y]--;
				ent[x]++;
			}
			else if (arr[y][x] == 1) {
				arr[y][x] = 0;
				arr[x][y] = 1;
				ent[x]--;
				ent[y]++;
			}
		}
		queue <int> q;
		for (i = 1; i <= n; i++) {
			if (ent[i] <= 0) q.push(i);
		}
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			ans.push_back(now);
			che[now] = 1;
			int res = 0;
			for (i = 1; i <= n; i++) {
				if (arr[now][i] == 1) {
					ent[i]--;
					if (ent[i] <= 0) {
						q.push(i);
						res++;
					}
				}
			}
			if (res >= 2) check = 1;
		}
		for (i = 1; i <= n; i++) if (che[i] == 0) check = 2;
		if (check == 0) {
			for (i = ans.size() - 1; i >= 0; i--) printf("%d ", ans[i]);
			printf("\n");
		}
		else if (check == 1) printf("?\n");
		else if (check == 2) printf("IMPOSSIBLE\n");
		for (i = 0; i <= n; i++) rk[i] = 0, ent[i] = 0, che[i] = 0;
		for (i = 0; i <= n; i++) {
			for (j = 0; j <= n; j++) {
				arr[i][j] = 0;
			}
		}
		ans.clear();
		check = 0;
	}
	return 0;
}