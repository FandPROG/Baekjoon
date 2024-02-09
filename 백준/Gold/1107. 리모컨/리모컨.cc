#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

int n;
int m, l;
int butt[11];
int ans[10];
int mn = 2e9;
int cnt;

int pand(int x)
{
    int i;
    while (x >= 10) {
        if (butt[x % 10] == 0) return 1;
        x /= 10;
        cnt++;
    }
    if (butt[x] == 0) return 1;
    return 0;
}

int main()
{
    int i, j;
    scanf("%d", &n);
    scanf("%d", &m);
    for (i = 0; i <= 10; i++) butt[i] = 1;
    for (i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        butt[x] = 0;
    }
    int lw = n, hg = n;
    int cnt1 = abs(100 - n), cnt2 = 0, cnt3 = 0;
    while (1) {
        cnt = 1;
        if (pand(lw) == 0) {
            cnt2 += cnt;
            break;
        }
        cnt2++;
        lw--;
        if (lw < 0) {
            cnt2 = 2e9;
            break;
        }
    }
    while (1) {
        cnt = 1;
        if (pand(hg) == 0) {
            cnt3 += cnt;
            break;
        }
        cnt3++;
        hg++;
        if (1000000 < hg) {
            cnt3 = 2e9;
            break;
        }
    }
    printf("%d", min(cnt1, min(cnt2, cnt3)));
    return 0;
}