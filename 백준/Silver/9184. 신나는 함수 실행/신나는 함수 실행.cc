#include <stdio.h>

int dp[55][55][55];

int DFS(int a, int b, int c) 
{
	if (a <= 0 || b <= 0 || c <= 0) {
		return 1;
	}
	else if (a > 20 || b > 20 || c > 20) {
		return DFS(20, 20, 20);
	}
	else if (dp[a][b][c] != 0) {
		return dp[a][b][c];
	}
	else if (a < b && b < c) {
		dp[a][b][c] = DFS(a, b, c - 1) + DFS(a, b - 1, c - 1) - DFS(a, b - 1, c);
	}
	else {
		dp[a][b][c] = DFS(a - 1, b, c) + DFS(a - 1, b - 1, c) + DFS(a - 1, b, c - 1) - DFS(a - 1, b - 1, c - 1);
	}
	return dp[a][b][c];
}


int main()
{
	int i, j, k;
	while (1) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == -1 && b == -1 && c == -1) break;
		printf("w(%d, %d, %d) = %d\n", a, b, c, DFS(a, b, c));
	}
	return 0;
}