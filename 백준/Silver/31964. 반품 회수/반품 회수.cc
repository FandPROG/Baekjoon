#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int X[3010], T[3010];
int MaxWaiting;

int main()
{
    int i, j;
    scanf("%d", &n);
    for(i=0;i<n;i++) scanf("%d", &X[i]);
    for(i=0;i<n;i++) scanf("%d", &T[i]);
    for(i=0;i<n;i++) {
        MaxWaiting = max(MaxWaiting, T[i] - (2 * X[n - 1] - X[i]));
    }
    printf("%d", X[n - 1] * 2 + MaxWaiting);
    return 0;
}