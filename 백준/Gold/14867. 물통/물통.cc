#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>

using namespace std;

int n, m, ex, ey;
map <pair<int, int>, int> dis;
pair<int, int> imsi;
int cnt;

void BFS(int x, int y)
{
	int i, j;
	queue <pair<int, int>> q;
	q.push({ x, y });
	imsi = { x, y };
	dis[imsi] = 1;
	while (!q.empty()) {
		int nx = q.front().first, ny = q.front().second;
		int nw = dis[{nx, ny}];
		q.pop();
		imsi = { nx, 0 };
		if (dis.find(imsi) == dis.end()) {
			dis.insert({ imsi, nw + 1 });
			q.push(imsi);
		}
		imsi = { 0, ny };
		if (dis.find(imsi) == dis.end()) {
			dis.insert({ imsi, nw + 1 });
			q.push(imsi);
		}
		imsi = { nx, m };
		if (dis.find(imsi) == dis.end()) {
			dis.insert({ imsi, nw + 1 });
			q.push(imsi);
		}
		imsi = { n, ny };
		if (dis.find(imsi) == dis.end()) {
			dis.insert({ imsi, nw + 1 });
			q.push(imsi);
		}
		if (n - nx >= ny) imsi = { nx + ny, 0 };
		else imsi = { n, ny - (n - nx) };
		if (dis.find(imsi) == dis.end()) {
			dis.insert({ imsi, nw + 1 });
			q.push(imsi);
		}
		if (m - ny >= nx) imsi = { 0 , nx + ny };
		else imsi = { nx - (m - ny), m };
		if (dis.find(imsi) == dis.end()) {
			dis.insert({ imsi, nw + 1 });
			q.push(imsi);
		}
	}
	return;
}


int main()
{
	int i, j;
	scanf("%d %d %d %d", &n, &m, &ex, &ey);
	BFS(0, 0);
	printf("%d", dis[{ex, ey}] - 1);
	return 0;
}