#include <stdio.h>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

long long s, e;
map <long long, long long> dis;

void BFS(long long x)
{
	priority_queue <long long> q;
	q.push(-x);
	while (!q.empty()) {
		long long now = -q.top();
		if (now >= e) break;
		q.pop();
		long long nw = now * 2;
		if (dis.find(nw) == dis.end()) {
			dis.insert({ nw, dis[now] + 1 });
			q.push(-nw);
		}
		nw = now * 10 + 1;
		if (dis.find(nw) == dis.end()) {
			dis.insert({ nw, dis[now] + 1 });
			q.push(-nw);
		}
	}
}

int main()
{
	scanf("%lld %lld", &s, &e);
	BFS(s);
	if (dis.find(e) == dis.end()) printf("-1");
	else printf("%lld", dis[e] + 1);
	return 0;
}