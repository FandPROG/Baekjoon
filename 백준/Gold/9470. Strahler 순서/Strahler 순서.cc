#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int k, m, p;
int ans[1010], ent[1010];
vector <int> vec[1010], nd[1010];

int main()
{
    int i , j;
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d", &k, &m, &p);
        for(i=0;i<p;i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            vec[x].push_back(y);
            ent[y]++;
        }
        queue <int> q;
        for(i=1;i<=m;i++) {
            if(ent[i] == 0) q.push(i), ans[i] = 1;
        }
        while(!q.empty()) {
            int now = q.front();
            q.pop();
            for(i=0;i<vec[now].size();i++) {
                int nw = vec[now][i];
                ent[nw]--;
                nd[nw].push_back(ans[now]);
                if(ent[nw] == 0) {
                    int val = -2e9, cnt;
                    for(j=0;j<nd[nw].size();j++) {
                        if(val == nd[nw][j]) cnt++;
                        else if(val < nd[nw][j]) val = nd[nw][j], cnt = 1;
                    }
                    if(cnt < 2) ans[nw] = val;
                    else ans[nw] = val + 1;
                    q.push(nw);
                }
            }
        }
        printf("%d %d\n", k, ans[m]);
        for(i=0;i<=m;i++) ans[i] = 0, ent[i] = 0;
        while(!q.empty()) q.pop();
        for(i=1;i<=m;i++) nd[i].clear(), vec[i].clear();
    }
}