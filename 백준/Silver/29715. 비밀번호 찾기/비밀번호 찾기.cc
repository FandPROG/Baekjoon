#include <stdio.h>

using ll = long long;

int n, m;
ll x, y;
ll ans = 1;
int cnt0 = 0, cnt1 = 0;

ll combi[15][15];

ll res9;

int main()
{
    int i, j;
    scanf("%d %d", &n, &m);
    for(i=0;i<=9;i++) {
        for(j=0;j<=i;j++) {
            if(j == 0 || i == j) combi[i][j] = 1;
            else combi[i][j] = combi[i - 1][j] + combi[i - 1][j - 1];
        }
    }
    scanf("%lld %lld", &x, &y);
    for(i=0;i<m;i++) {
        int xx, yy;
        scanf("%d %d", &xx, &yy);
        if(xx == 0) cnt0++;
        else cnt1++;
    }
    ll fac = (n - cnt1);
    ll com1 = (9 - cnt0 - cnt1);
    ll com2 = (fac - cnt0);
    for(i=2;i<=fac;i++) {
        ans *= i;
    }
    ans *= combi[com1][com2];

    ll ans3d = ans / 3;
    if(ans % 3 == 0) ans3d--;

    ll last_res = (ans * x) + (ans3d * y);
    printf("%lld", last_res);
    return 0;
}