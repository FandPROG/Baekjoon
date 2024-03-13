#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
vector<int> group[1010], vec[100010];
int dis[100010];
int ch[100010];
int gr_ch[1010];

void BFS(int x)
{
    int i, j;
    queue <int> q;
    q.push(x);
    dis[x] = 0;
    ch[x] = 1;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(i=0;i<vec[now].size();i++) {
            int nw = vec[now][i];
            if(gr_ch[nw] == 1) continue;
            gr_ch[nw] = 1;
            for(j=0;j<group[nw].size();j++) {
                int nnw = group[nw][j];
                if(ch[nnw] == 1) continue;
                ch[nnw] = 1;
                dis[nnw] = dis[now] + 1;
                q.push(nnw);
            }
        }
    }
}

int main()
{
    int i, j;
    scanf("%d %d %d", &n, &k, &m);
    for(i=0;i<m;i++) {
        for(j=0;j<k;j++) {
            int x;
            scanf("%d", &x);
            vec[x].push_back(i);
            group[i].push_back(x);
        }
    }
    BFS(1);
    if(ch[n] == 0) printf("-1");
    else printf("%d", dis[n] + 1);
    return 0;
}