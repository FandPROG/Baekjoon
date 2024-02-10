#include <stdio.h>
#include <queue>

using namespace std;

int dis[110];
int n, m;
int arr[110];

void BFS(int x)
{
    queue <int> q;
    q.push(x);
    dis[x] = 0;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 1; i <= 6; i++) {
            if (arr[now + i] != 0) {
                if (dis[arr[now + i]] > dis[now] + 1) {
                    dis[arr[now + i]] = dis[now] + 1;
                    q.push(arr[now + i]);
                }
            }
            else if (now + i > 100 && dis[100] > dis[now] + 1) dis[100] = dis[now] + 1;
            else if (dis[now + i] > dis[now] + 1) {
                dis[now + i] = dis[now] + 1;
                q.push(now + i);
            }
        }
    }
}

int main()
{
    int i, j;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n + m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        arr[x] = y;
    }
    for (i = 0; i <= 100; i++) dis[i] = 2e9;
    BFS(1);
    printf("%d", dis[100]);
    return 0;
}