 
#include <stdio.h>
 
int a, b[100010] = {0,}, i, j, sum[100010] = {0,}, c, g = -999;
 
int main()
{
    scanf("%d %d", &a, &c);
    for(i=1;i<=a;i++) {
        scanf("%d", &b[i]);
        sum[0] = b[0];
        if(i == 0) continue;
        sum[i] = sum[i-1] + b[i];
    }
    g = sum[c];
    for(i=2;i<=a;i++) {
        if(i+c-1 > a) break;
        if(g < sum[i+c-1]-sum[i-1]) g = sum[i+c-1]-sum[i-1];
    }
    printf("%d", g);
    return 0;
}