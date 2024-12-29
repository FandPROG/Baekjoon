#include <stdio.h>
#include <algorithm>

using namespace std;
using ll = long long;

int n;
int arr[100010];
ll sum, mx;

int main()
{
    int i, j;
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        scanf("%d", &arr[i]);
        mx = max(mx, (ll)arr[i]);
        sum += arr[i];
    }
    if(arr[0] == 1 && n == 1) printf("Happy");
    else if(mx * 2 > sum) printf("Unhappy");
    else printf("Happy");
    return 0;
}