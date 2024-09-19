#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int i, j;
    int n;
    scanf("%d", &n);
    int ans = 180 * (n - 1);
    int sum = 0;
    for(i=0;i<n;i++) {
        int x;
        scanf("%d", &x);
        sum += (2 * x);
    }
    printf("%d", ans - sum);
    return 0;
}