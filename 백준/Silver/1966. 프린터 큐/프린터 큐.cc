#include <stdio.h>
#include <queue>

using namespace std;

int t;

int main()
{
    int i, j;
    scanf("%d", &t);
    for (i = 0; i < t; i++) {
        int n, m;
        queue <pair<int, int>> q;
        priority_queue <int> pq;
        scanf("%d %d", &n, &m);
        for (j = 0; j < n; j++) {
            int x;
            scanf("%d", &x);
            q.push({ x, j });
            pq.push(x);
        }
        int ans = 0;
        while (!q.empty()) {
            int val = q.front().first, idx = q.front().second;
            q.pop();
            if (pq.top() == val) {
                pq.pop();
                ans++;
                if (idx == m) {
                    printf("%d\n", ans);
                    break;
                }
            }
            else q.push({ val, idx });
        }
    }
    return 0;
}