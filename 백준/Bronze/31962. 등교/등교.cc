#include <stdio.h>
#include <vector>

using namespace  std;

int n, k;

int main()
{
    int i, j;
    scanf("%d %d", &n, &k);
    int ans = -1;
    for(i=0;i<n;i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if(x + y > k) continue;
        else {
            if(x > ans) ans = x;
        }
    }
    printf("%d", ans);
}