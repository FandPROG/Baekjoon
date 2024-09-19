#include <stdio.h>
#include <algorithm>

using namespace std;

int n, m, k;
char map[510][510];
int cnt[510][510][50];
int ans[510][510];
int res;

void getcnt(int x, int y)
{
    int i, j;
    for(i=0;i<k;i++) {
        for(j=0;j<k;j++) {
            cnt[i][j][map[x + i][y + j] - 'A']++;
        }
    }
    return;
}

void printmap(int x, int y)
{
    int i, j;
    for(i=0;i<k;i++) {
        for(j=0;j<k;j++) {
            if(map[x + i][y + j] != ans[i][j]) res++;
            map[x + i][y + j] = ans[i][j];
        }
    }
    return;
}

int main()
{
    int i, j;
    scanf("%d %d %d", &n, &m, &k);
    for(i=0;i<n;i++) scanf("%s", map[i]);
    for(i=0;i<=n-k;i+=k) {
        for(j=0;j<=m-k;j+=k) {
            getcnt(i, j);
        }
    }
    for(i=0;i<k;i++) {
        for(j=0;j<k;j++) {
            int mx = 0;
            int mxidx = 0;
            for(int l=0;l<26;l++) {
                if(mx < cnt[i][j][l]) {
                    mx = cnt[i][j][l];
                    mxidx = l;
                }
            }
            ans[i][j] = mxidx + 'A';
        }
    }
    for(i=0;i<=n-k;i+=k) {
        for(j=0;j<=m-k;j+=k) {
            printmap(i, j);
        }
    }
    printf("%d\n", res);
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    return 0;
}