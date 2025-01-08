#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

int n;
ll arr[610];
ll ans = (ll)1e9 * (ll)1e9 + (ll)7;

int main()
{
    int i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++) 
        scanf("%lld", &arr[i]);
    
    sort(arr, arr + n);

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            ll snowman1 = arr[i] + arr[j];
            int low = 0, high = n - 1;
            while (low < high) {
                if (low == i || low == j) {
                    low++;
                    continue;
                }
                if (high == i || high == j) {
                    high--;
                    continue;
                }
                if (low >= high) break;

                ll snowman2 = arr[low] + arr[high];
                ans = min(ans, abs(snowman1 - snowman2));
                
                if (snowman1 < snowman2) {
                    high--;
                } else {
                    low++;
                }
            }
        }
    }

    printf("%lld", ans);
    return 0;
}
