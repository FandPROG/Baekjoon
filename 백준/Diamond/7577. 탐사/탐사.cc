#include <stdio.h>

int l, n, w[110][110];

int main()
{
    int i, j, k;
    scanf("%d %d", &l, &n);
    for (i = 0; i <= l; i++) {
        for (j = 0; j <= l; j++) {
            if (i != j) w[i][j] = 987654321;
        }
    }
    for (i = 0; i < l; i++) w[i + 1][i] = 0, w[i][i + 1] = 1;
    for (i = 0; i < n; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (w[a - 1][b] > c) w[a - 1][b] = c;
        w[b][a - 1] = -c;
    }
    for (i = 0; i <= l; i++) {
        for (j = 0; j <= l; j++) {
            for (k = 0; k <= l; k++) {
                if (w[j][i] + w[i][k] < w[j][k]) w[j][k] = w[j][i] + w[i][k];
            }
        }
    }
    for (i = 0; i <= l; i++) if (w[i][i] < 0) {
        printf("NONE");
        return 0;
    }
    for (i = 0; i < l; i++) {
        int cn = w[0][i + 1] - w[0][i];
        if (cn == 0) printf("-");
        else printf("#");
    }
    return 0;
}