#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector <int> vec[110];
int dis[110], ch[110];
int se, ss;

int main()
{
	int i, j;
	scanf("%d %d %d %d", &n, &ss, &se, &m);
	for (i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	queue <int> q;
	q.push(ss);
	while (!q.empty()) {
		int nw = q.front();
		if (nw == se) {
			printf("%d", dis[se]);
			return 0;
		}
		q.pop();
		for (i = 0; i < vec[nw].size(); i++) {
			int now = vec[nw][i];
			if (ch[now] == 1) continue;
			ch[now] = 1;
			dis[now] = dis[nw] + 1;
			q.push(now);
		}
	}
	printf("-1");
	return 0;
}