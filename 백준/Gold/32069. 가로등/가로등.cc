#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

#define MAX 1000000000000000000

using namespace std;
using ull = unsigned long long;

ull L;
int N, K;
vector <int> ans;
queue <pair<ull, int>> q;
set <ull> ch;
int cnt = 0;

void BFS()
{
    int i, j;
    while(!q.empty()) {
        if(cnt >= K) break;
        ull now = q.front().first;
        int val = q.front().second;
        q.pop();
        ull nw;
        if(now > 0) {
            nw = now - 1;
            if(ch.find(nw) == ch.end()) {
                cnt++;
                q.push({nw, val + 1});
                ch.insert(nw);
                ans.push_back(val + 1);
                if(cnt >= K) break;
            }
        }
        nw = now + 1;
        if(nw <= L && ch.find(nw) == ch.end()) {
            cnt++;
            q.push({nw, val + 1});
            ch.insert(nw);
            ans.push_back(val + 1);
            if(cnt >= K) break;
        }
        if(cnt >= K) break;
    }
}

int main()
{
    int i, j;
    scanf("%llu %d %d", &L, &N, &K);
    for(i=0;i<N;i++) {
        ull x;
        scanf("%llu", &x);
        ch.insert(x);
        q.push({x, 0});
        ans.push_back(0);
        cnt++;
    }
    BFS();
    sort(ans.begin(), ans.end());
    for(i=0;i<K;i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}