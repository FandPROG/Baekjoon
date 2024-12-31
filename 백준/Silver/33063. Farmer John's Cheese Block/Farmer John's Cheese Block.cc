#include <stdio.h>
#include <algorithm>

using namespace std;

int chxy[1010][1010];
int chxz[1010][1010];
int chyz[1010][1010];
int n, q;

int main()
{
    int i, j;
    scanf("%d %d", &n, &q);
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            chxy[i][j] = n;
            chxz[i][j] = n;
            chyz[i][j] = n;
        }
    }
    int ans = 0;
    while(q--) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        chxy[x][y]--;
        chxz[x][z]--;
        chyz[y][z]--;
        if(chxy[x][y] == 0) ans++;
        if(chxz[x][z] == 0) ans++;
        if(chyz[y][z] == 0) ans++;
        printf("%d\n", ans);
    }
    return 0;
}