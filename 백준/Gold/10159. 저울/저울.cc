#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector<int> vec1[110], vec[110];
int ch[110], ch1[110];
int ans[110];

void BFS1(int x)
{
	queue <int> q;
	ch1[x] = 1;
	q.push(x);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < vec1[now].size(); i++) {
			int nw = vec1[now][i];
			if (ch1[nw] == 0) {
				ch1[nw] = 1;
				q.push(nw);
			}
		}
	}
	return;
}

void BFS(int x)
{
	queue <int> q;
	ch[x] = 1;
	q.push(x);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < vec[now].size(); i++) {
			int nw = vec[now][i];
			if (ch[nw] == 0) {
				ch[nw] = 1;
				q.push(nw);
			}
		}
	}
	return;
}

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		vec[x].push_back(y);
		vec1[y].push_back(x);
	}
	for (i = 1; i <= n; i++) {
		BFS(i);
		BFS1(i);
		int cnt = 0;
		for (j = 1; j <= n; j++) {
			if (ch[j] == 0 && ch1[j] == 0) cnt++;
		}
		ans[i] = cnt;
		for (j = 1; j <= n; j++) ch[j] = 0, ch1[j] = 0;
	}
	for (i = 1; i <= n; i++) printf("%d\n", ans[i]);
	return 0;
}