#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector <int> vec[1010];
vector <int> rk[1010];
int ent[1010], ch[1010];
vector <int> ans;
queue <int> q;

int main()
{
    int i, j;
    scanf("%d %d", &n, &m);
    for(i=0;i<m;i++) {
        int x;
        scanf("%d", &x);
        for(j=0;j<x;j++) {
            int y;
            scanf("%d", &y);
            rk[i].push_back(y);
        }
    }
    for(i=0;i<m;i++) {
        for(j=0;j<rk[i].size();j++) {
            for(int l = 0;l<j;l++) {
                vec[rk[i][j]].push_back(rk[i][l]);
                ent[rk[i][l]]++;
            }
        }
    }
    for(i=1;i<=n;i++) if(ent[i] == 0) q.push(i);
    while(!q.empty()) {
        int now = q.front();
        ch[now] = 1;
        ans.push_back(now);
        q.pop();
        for(i=0;i<vec[now].size();i++) {
            int nw = vec[now][i];
            ent[nw]--;
            if(ent[nw] == 0) q.push(nw);
        }
    }
    for(i=1;i<=n;i++) {
        if(ch[i] == 0) {
            printf("0");
            return 0;
        }
    }
    for(i=ans.size()-1;i>=0;i--) printf("%d\n", ans[i]);
    return 0;
}