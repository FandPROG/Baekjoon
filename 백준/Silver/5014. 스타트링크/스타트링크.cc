#include <stdio.h>
#include <queue>

using namespace std;

int f, s, g, u, d;
int dis[1000010];

void BFS(int x)
{
	int i;
	queue <int> q;
	q.push(x);
	dis[x] = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now + u <= f && dis[now] + 1 < dis[now + u]) {
			dis[now + u] = dis[now] + 1;
			q.push(now + u);
		}
		if (now - d >= 1 && dis[now] + 1 < dis[now - d]) {
			dis[now - d] = dis[now] + 1;
			q.push(now - d);
		}
	}
	return;
}

int main()
{
	int i, j;
	scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
	for (i = 1; i <= f; i++) dis[i] = 2e9;
	BFS(s);
	if (dis[g] == 2e9) printf("use the stairs");
	else printf("%d", dis[g]);
	return 0;
}