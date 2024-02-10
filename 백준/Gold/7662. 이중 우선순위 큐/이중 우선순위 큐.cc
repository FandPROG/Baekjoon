#include <stdio.h>
#include <queue>

using namespace std;

priority_queue <pair<long long, long long>> pq1, pq2;
long long t, cnt = 0;
bool ch[1000010];

int main()
{
    long long i, j;
    scanf("%lld", &t);
    for (i = 0; i < t; i++) {
        int n;
        scanf("%lld", &n);
        cnt = 0;
        for (j = 0; j <= n; j++) ch[j] = 0;
        for (j = 0; j < n; j++) {
            long long x;
            char c;
            scanf(" %c", &c);
            scanf("%lld", &x);
            if (c == 'I') pq1.push({ x, cnt }), pq2.push({ -x, cnt++ });
            if (c == 'D') {
                if (x == 1) {
                    while (!pq1.empty()) {
                        if (ch[pq1.top().second] == 0) break;
                        pq1.pop();
                    }
                    if (!pq1.empty()) {
                        ch[pq1.top().second] = 1;
                        pq1.pop();
                    }
                }
                else if (x == -1) {
                    while (!pq2.empty()) {
                        if (ch[pq2.top().second] == 0) break;
                        pq2.pop();
                    }
                    if (!pq2.empty()) {
                        ch[pq2.top().second] = 1;
                        pq2.pop();
                    }
                }
            }
        }
        while (!pq1.empty()) {
            if (ch[pq1.top().second] == 0) break;
            pq1.pop();
        }
        while (!pq2.empty()) {
            if (ch[pq2.top().second] == 0) break;
            pq2.pop();
        }
        if (pq1.empty()) printf("EMPTY\n");
        else printf("%lld %lld\n", pq1.top().first, pq2.top().first * (-1));
        while(!pq1.empty()) {
            pq1.pop();
        }
        while(!pq2.empty()) {
            pq2.pop();
        }
    }
    return 0;
}
