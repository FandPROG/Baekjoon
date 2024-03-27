#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int ans[1010], ent[1010];
int way[1010];
vector <pair<int, int>> vec[1010];
vector <int> ans_way;

void find(int x)
{
    if(x == way[x]) return;
    ans_way.push_back(x);
    find(way[x]);
}

int main()
{
    int i, j;
    scanf("%d %d", &n, &m);
    for(i=0;i<m;i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        if(x == 1) {
            ans[y] = z;
        }
        else {
            vec[x].push_back({y, z});
            ent[y]++;
        }
    }
    queue <int> q;
    for(i=1;i<=n;i++) if(ent[i] == 0) q.push(i);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(i=0;i<vec[now].size();i++) {
            int nidx = vec[now][i].first, nval = vec[now][i].second;
            if(ans[now] + nval > ans[nidx]) {
                ans[nidx] = ans[now] + nval;
                way[nidx] = now;
            }
            ent[nidx]--;
            if(ent[nidx] == 0) q.push(nidx);
        }
    }
    find(1);
    printf("%d\n", ans[1]);
    printf("1 ");
    for(i=ans_way.size()-1;i>=0;i--) printf("%d ", ans_way[i]);
    return 0;
}