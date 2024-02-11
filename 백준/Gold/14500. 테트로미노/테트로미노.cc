#include <stdio.h>

int n, m;
int map[510][510];
int ans;

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	//1번 테트로미노
	int sum = 0;
	for (i = 0; i <= n - 4; i++) {
		for (j = 0; j < m; j++) {
			for (int k = 0; k < 4; k++) sum += map[i + k][j];
			if (ans < sum) ans = sum;
			sum = 0;
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j <= m - 4; j++) {
			for (int k = 0; k < 4; k++) sum += map[i][j + k];
			if (ans < sum) ans = sum;
			sum = 0;
		}
	}
	//2번 테트로미노
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < m - 1; j++) {
			sum = map[i][j] + map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1];
			if (sum > ans) ans = sum;
		}
	}
	//3, 4, 5번 테트로미노(가로) 전체 - 뻬어진부분
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < m - 2; j++) {
			sum = map[i][j] + map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j + 2] + map[i][j + 2];
			//3번경우
			int sum3 = sum - map[i][j] - map[i][j + 1];
			if (sum3 > ans) ans = sum3;
			sum3 = sum - map[i][j + 1] - map[i][j + 2];
			if (sum3 > ans) ans = sum3;
			sum3 = sum - map[i + 1][j] - map[i + 1][j + 1];
			if (sum3 > ans) ans = sum3;
			sum3 = sum - map[i + 1][j + 1] - map[i + 1][j + 2];
			if (sum3 > ans) ans = sum3;
			// 4번경우
			int sum4 = sum - map[i][j] - map[i + 1][j + 2];
			if (sum4 > ans) ans = sum4;
			sum4 = sum - map[i + 1][j] - map[i][j + 2];
			if (sum4 > ans) ans = sum4;
			// 5번경우
			int sum5 = sum - map[i][j] - map[i][j + 2];
			if (sum5 > ans) ans = sum5;
			sum5 = sum - map[i + 1][j] - map[i + 1][j + 2];
			if (sum5 > ans) ans = sum5;
		}
	}
	//3, 4, 5번 테트로미노(세로) 전체 - 뻬어진부분
	for (i = 0; i < n - 2; i++) {
		for (j = 0; j < m - 1; j++) {
			sum = map[i][j] + map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1] + map[i + 2][j];
			//3번인경우
			int sum3 = sum - map[i][j] - map[i + 1][j];
			if (sum3 > ans) ans = sum3;
			sum3 = sum - map[i + 1][j] - map[i + 2][j];
			if (sum3 > ans) ans = sum3;
			sum3 = sum - map[i][j + 1] - map[i + 1][j + 1];
			if (sum3 > ans) ans = sum3;
			sum3 = sum - map[i + 1][j + 1] - map[i + 2][j + 1];
			if (sum3 > ans) ans = sum3;
			// 4번경우
			int sum4 = sum - map[i][j] - map[i + 2][j + 1];
			if (sum4 > ans) ans = sum4;
			sum4 = sum - map[i][j + 1] - map[i + 2][j];
			if (sum4 > ans) ans = sum4;
			// 5번경우
			int sum5 = sum - map[i][j] - map[i + 2][j];
			if (sum5 > ans) ans = sum5;
			sum5 = sum - map[i][j + 1] - map[i + 2][j + 1];
			if (sum5 > ans) ans = sum5;
		}
	}
	printf("%d", ans);
	return 0;
}