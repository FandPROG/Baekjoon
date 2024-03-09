#include <stdio.h>
#include <algorithm> 
#include <vector>

using namespace std;

int dp[55][55][55][55];
int rec[55][55];

int Div(int x, int y)
{
	int i, j;
	if (x == y) return rec[x][y] = 1;
	if (x < 0 || y < 0) return 2e9;
	if (rec[x][y] != -1) return rec[x][y];
	rec[x][y] = x * y;
	if (x >= 3 * y) rec[x][y] = min(rec[x][y], Div(x - y, y) + 1);
	else {
		for (i = 1; i <= (y + 1) / 2; i++) rec[x][y] = min(rec[x][y], Div(x, i) + Div(x, y - i));
		for (i = 1; i <= (x + 1) / 2; i++) rec[x][y] = min(rec[x][y], Div(i, y) + Div(x - i, y));
	}
	return rec[x][y];
}

int ans(int w1, int h1, int w2, int h2)
{
	int i, j;
	if (dp[w1][h1][w2][h2] != -1) return dp[w1][h1][w2][h2];
	dp[w1][h1][w2][h2] = 2e9;
	for (i = 1; i < h1; i++) {
		if (i < h2) dp[w1][h1][w2][h2] = min(dp[w1][h1][w2][h2], ans(w1, h1 - i, w2, h2 - i) + Div(w1 - w2, i));
		else if (i > h2) dp[w1][h1][w2][h2] = min(dp[w1][h1][w2][h2], ans(w1, i, w2, h2) + Div(w1, h1 - i));
		else if (i == h2) dp[w1][h1][w2][h2] = min(dp[w1][h1][w2][h2], Div(w1, h1 - i) + Div(w1 - w2, i));
	}
	for (i = 1; i < w1; i++) {
		if (i < w2) dp[w1][h1][w2][h2] = min(dp[w1][h1][w2][h2], ans(w1 - i, h1, w2 - i, h2) + Div(i, h1 - h2));
		else if (i > w2) dp[w1][h1][w2][h2] = min(dp[w1][h1][w2][h2], ans(i, h1, w2, h2) + Div(w1 - i, h1));
		else if (i == w2) dp[w1][h1][w2][h2] = min(dp[w1][h1][w2][h2], Div(i, h1 - h2) + Div(w1 - i, h1));
	}
	return dp[w1][h1][w2][h2];
}

int main()
{
	int i, j;
	int h1, w1, h2, w2;
	scanf("%d %d %d %d", &h1, &w1, &h2, &w2);
	for (i = 0; i <= w1; i++) {
		for (j = 0; j <= h1; j++) {
			rec[i][j] = -1;
		}
	}
	for (i = 1; i <= w1; i++) {
		for (j = 1; j <= h1; j++) {
			for (int k = 1; k <= w2; k++) {
				for (int l = 1; l <= h2; l++) {
					dp[i][j][k][l] = -1;
				}
			}
		}
	}
	printf("%d", ans(w1, h1, w2, h2));
	return 0;
}