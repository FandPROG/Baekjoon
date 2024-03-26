#include <stdio.h>
#define INF 2e9

int n, m, node[5][6010];
long long int d[510];

int main()
{
    int i, j, a, b, c;
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &node[0][i], &node[1][i], &node[2][i]);
    }
    for (i = 0; i <= n; i++) d[i] = INF;
    d[1] = 0;
    for (i = 1; i <= n - 1; i++) {
        for (j = 0; j < m; j++) {
            if (d[node[0][j]] != INF) {
                if (d[node[0][j]] + node[2][j] < d[node[1][j]]) {
                    d[node[1][j]] = d[node[0][j]] + node[2][j];
                }
            }
        }
    }
    for (i = 0; i < m; i++) {
        if (d[node[0][i]] + node[2][i] < d[node[1][i]] && d[node[0][i]] != INF) {
            printf("-1");
            return 0;
        }
    }
    for (i = 2; i <= n; i++) {
        if (d[i] == INF) printf("-1\n");
        else printf("%lld\n", d[i]);
    }
    return 0;
}   