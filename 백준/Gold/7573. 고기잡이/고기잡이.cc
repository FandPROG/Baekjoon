#include <stdio.h>
#include <algorithm>

using namespace std;

int a, b, l, x[100], y[100];

int main()
{
	int level;
	int i, j, m, n, cnt = 0, mx = -2e9, m_x, m_y;
	bool broke = 0;
	scanf("%d %d %d", &a, &l, &b);
	for (i = 0; i < b; i++) {
		scanf("%d %d", &x[i], &y[i]);
	}
	for (i = 0; i < b; i++) {
		for (j = i; j < b; j++) {
			m_x = min(x[i], x[j]);
			m_y = min(y[i], y[j]);
			for (int k = 1; k < l / 2; k++) {
				for (n = 0; n < b; n++) if (m_x <= x[n] && x[n] <= m_x + k && m_y <= y[n] && y[n] <= m_y + (l / 2 - k)) cnt++;
				if (cnt > mx) mx = cnt;
				cnt = 0;
			}
		}
	}
	printf("%d", mx);
	return 0;
}