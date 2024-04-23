#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int chs[10][10], chg[10][10];
int chsq[10][10];
int m_sq[10][10];
int ch = 0;
vector <pair<int, int>> emp;

int sqnumjudge(int x, int y)
{
	if (0 <= x && x <= 2 && 0 <= y && y <= 2) return 1;
	if (0 <= x && x <= 2 && 3 <= y && y <= 5) return 2;
	if (0 <= x && x <= 2 && 6 <= y && y <= 8) return 3;

	if (3 <= x && x <= 5 && 0 <= y && y <= 2) return 4;
	if (3 <= x && x <= 5 && 3 <= y && y <= 5) return 5;
	if (3 <= x && x <= 5 && 6 <= y && y <= 8) return 6;

	if (6 <= x && x <= 8 && 0 <= y && y <= 2) return 7;
	if (6 <= x && x <= 8 && 3 <= y && y <= 5) return 8;
	if (6 <= x && x <= 8 && 6 <= y && y <= 8) return 9;

	return 0;
}

void place_magic_sq(int x)
{
	int i, j;
	if (x >= emp.size()) {
		ch = 1;
		return;
	}
	for (i = 1; i <= 9; i++) {
		int a = emp[x].first, b = emp[x].second;
		int nsq = sqnumjudge(a, b);
		if (chs[a][i] == 1) continue;
		if (chg[b][i] == 1) continue;
		if (chsq[nsq][i] == 1) continue;
		chsq[nsq][i] = 1;
		chg[b][i] = 1;
		chs[a][i] = 1;
		m_sq[a][b] = i;
		place_magic_sq(x + 1);
		if (ch == 1) return;
		chsq[nsq][i] = 0;
		chg[b][i] = 0;
		chs[a][i] = 0;
	}
	return;
}

int main()
{
	int i, j;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			scanf("%d", &m_sq[i][j]);
			if (m_sq[i][j] == 0) emp.push_back({ i, j });
			else {
				chsq[sqnumjudge(i, j)][m_sq[i][j]] = 1;
				chs[i][m_sq[i][j]] = 1;
				chg[j][m_sq[i][j]] = 1;
			}
		}
	}
	place_magic_sq(0);
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			printf("%d ", m_sq[i][j]);
		}
		printf("\n");
	}
	return 0;
}