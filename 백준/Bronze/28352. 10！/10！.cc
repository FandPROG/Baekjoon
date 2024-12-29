#include <stdio.h>
#include <algorithm>

int main()
{
    int i, j;
    int n;
    scanf("%d", &n);
    long long facto = 6;
    for(i=11;i<=n;i++) {
        facto *= i;
    }
    printf("%lld", facto);
    return 0;
}