#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    
    vector<vector<int>> graph(n);
    for(int i = 0; i < n - 1; i++) {
        int p, c;
        cin >> p >> c;
        graph[p].push_back(c);
        graph[c].push_back(p);
    }
    
    vector<int> apples(n);
    for(int i = 0; i < n; i++) {
        cin >> apples[i];
    }
    
    int ans = 0;
    for(int mask = 0; mask < (1 << n); mask++) {
        if(!(mask & 1)) continue;
        if(__builtin_popcount(mask) > k) continue;
        int visited = 0;
        queue<int> q;
        q.push(0);
        visited |= 1;
        
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int nxt : graph[cur]) {
                if((mask & (1 << nxt)) && !(visited & (1 << nxt))) {
                    visited |= (1 << nxt);
                    q.push(nxt);
                }
            }
        }
        if(visited == mask) {
            int total = 0;
            for(int i = 0; i < n; i++) {
                if(mask & (1 << i))
                    total += apples[i];
            }
            ans = max(ans, total);
        }
    }
    
    cout << ans;
    return 0;
}
