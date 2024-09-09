#include <stdio.h>
#include <vector>

using namespace std;

int n, k;
int ch1[410][410], ch2[410][410];

int main()
{
    int i, j, m;
    scanf("%d %d", &n, &k);
    for(i=0;i<k;i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        ch1[x][y] = 1;
        ch2[y][x] = 1;
    }
    for(m=1;m<=n;m++) {
        for(i=1;i<=n;i++) {
            for(j=1;j<=n;j++) {
                if(ch1[i][j] == 1) continue;
                if(ch1[i][m] == 1 && ch1[m][j] == 1) {
                    ch1[i][j] = 1;
                }
            }
        }
    }
    for(m=1;m<=n;m++) {
        for(i=1;i<=n;i++) {
            for(j=1;j<=n;j++) {
                if(ch2[i][j] == 1) continue;
                if(ch2[i][m] == 1 && ch2[m][j] == 1) {
                    ch2[i][j] = 1;
                }
            }
        }
    }
    int Q;
    scanf("%d", &Q);
    while(Q--) {
        int x, y;
        scanf("%d %d", &x, &y);
        if(ch1[x][y] == 1) printf("-1\n");
        else if(ch2[x][y] == 1) printf("1\n");
        else printf("0\n");
    }
    return 0;
}