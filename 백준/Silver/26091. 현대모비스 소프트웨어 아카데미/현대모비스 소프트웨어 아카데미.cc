#include <stdio.h>
#include <algorithm>

using namespace std;

int n, m;
int arr[100010];

int main()
{
    int i, j;
    scanf("%d %d", &n, &m);
    for(i=0;i<n;i++) scanf("%d", &arr[i]);
    sort(arr, arr + n);
    int high = n - 1, low = 0;
    int ans = 0;
    while(low < high) {
        int res = arr[low] + arr[high];
        if(res < m) {
            low++;
            continue;
        }
        ans++;
        //printf("%d %d\n", arr[low], arr[high]);
        high--;
        low++;
    }
    printf("%d", ans);
    return 0;
}