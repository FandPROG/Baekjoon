#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int ans;
vector <int> vec[1010];
int ch[1010];

void BFS(int s)
{
    int i;
    queue<int> q;
    q.push(s);
    ch[s] = 1;
    while (!q.empty()) 
    {
        int now = q.front();
        q.pop();
        for (i = 0; i < vec[now].size(); i++) {
            if (ch[vec[now][i]] == 1) continue;
            ch[vec[now][i]] = 1;
            q.push(vec[now][i]);
        }
    }
}

int main()
{
    int i, j;
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    for (i = 1; i <= n; i++) {
        if (ch[i] == 0) {
            ans++;
            BFS(i);
        }
    }
    printf("%d", ans);
    return 0;
}