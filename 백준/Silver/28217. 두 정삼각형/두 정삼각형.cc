#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int a[15][15], b[15][15];
int ans = 2e9, res[10][15][15];

int tri_chai(int x) {
	int i, j;
	int cnt = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j <= i; j++) {
			if (res[x][i][j] != b[i][j]) cnt++;
		}
	}
	return cnt;
}

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j <= i; j++) {
			scanf("%d", &a[i][j]);
			res[0][i][j] = a[i][j];
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j <= i; j++) {
			scanf("%d", &b[i][j]);
		}
	}
	for (int k = 1; k < 3; k++) {
		int x, y;
		for (i = 0; i < n; i++) {
			x = n - 1, y = i;
			for (j = 0; j <= i; j++) {
				res[k][i][j] = res[k - 1][x][y];
				x--;
				y--;
			}
		}
	}
	for (int k = 0; k < 3; k++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j <= i; j++) {
				res[k + 3][i][j] = res[k][i][i - j];
			}
		}
	}
	for (int k = 0; k < 6; k++) {
		ans = min(ans, tri_chai(k));
	}
	printf("%d", ans);
}