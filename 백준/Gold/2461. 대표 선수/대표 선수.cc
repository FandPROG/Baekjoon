#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int arr[1010][1010];
int n, m;

int main()
{
    int i, j;
    scanf("%d %d", &n, &m);
    vector <int> poi(n);
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) scanf("%d", &arr[i][j]);
        sort(arr[i], arr[i] + m);
    }
    int ans = 2e9;
    while(1) {
        int mx = -2e9, mx_idx;
        int mn = 2e9, mn_idx;
        for(i=0;i<poi.size();i++) {
            if(mx < arr[i][poi[i]]) {
                mx = arr[i][poi[i]];
                mx_idx = i;
            }
            if(mn > arr[i][poi[i]]) {
                mn = arr[i][poi[i]];
                mn_idx = i;
            }
        }
        ans = min(ans, mx - mn);
        if(poi[mn_idx] + 1 > m) break;
        else {
            poi[mn_idx]++;
        }
    }
    printf("%d", ans);
    return 0;
}