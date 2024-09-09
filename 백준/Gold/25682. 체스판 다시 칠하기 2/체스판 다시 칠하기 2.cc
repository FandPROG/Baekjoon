#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

char Bst[2010][2010];
char Wst[2010][2010];
int sum[2010][2010];
int n, m, k;
char map[2010][2010];
int ans = 2e9;

void chess_re_color(char C) {
    int i, j;
    Bst[1][1] = C;
    for(i=2;i<=n;i++) {
        if(Bst[i-1][1] == 'B') Bst[i][1] = 'W';
        else Bst[i][1] = 'B';
    }
    for(i=1;i<=n;i++) {
        for(j=2;j<=m;j++) {
            if(Bst[i][j-1] == 'B') Bst[i][j] = 'W';
            else Bst[i][j] = 'B';
        }
    }
    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            int res = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1];
            if(map[i][j] != Bst[i][j]) res++;
            sum[i][j] = res;
        }
    }
    for(i=k;i<=n;i++) {
        for(j=k;j<=m;j++) {
            int res = sum[i][j] - sum[i-k][j] - sum[i][j-k] + sum[i-k][j-k];
            ans = min(res, ans);
        }
    }
}

int main()
{
    int i;
    scanf("%d %d %d", &n, &m, &k);
    for(i=1;i<=n;i++) {
        scanf("%s", map[i] + 1);
    }
    chess_re_color('B');
    chess_re_color('W');
    printf("%d", ans);
    return 0;
}