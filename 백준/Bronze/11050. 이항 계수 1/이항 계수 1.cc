#include <stdio.h>


int n, k;

int main()
{
    scanf("%d %d", &n, &k);
    int ns = 1;
    for (int i = 0; i < k; i++) {
        ns *= (n-i);
    }
    for (int i = 1; i <= k; i++) {
        ns /= i;
    }
    printf("%d", ns);
}