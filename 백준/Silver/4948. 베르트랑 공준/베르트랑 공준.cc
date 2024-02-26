#include <stdio.h>

int prime[250000];

void IsPrime()
{
    int i, j;
    prime[1] = 1;
    for(i=2;i<250000;i++) {
        if(prime[i] == 1) continue;
        for(j=i*2;j<250000;j+=i) {
            prime[j] = 1;
        }
    }
    return;
}

int main()
{
    int i;
    IsPrime();
    while(1) {
        int x;
        scanf("%d", &x);
        if(x == 0) break;
        int res = 0;
        for(i=x + 1;i<=x*2;i++) {
            if(prime[i] == 0) res++;
        }
        printf("%d\n", res);
    }
    return 0;
}