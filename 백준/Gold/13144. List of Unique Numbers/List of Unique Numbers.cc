#include <stdio.h>
#include <vector>

using namespace std;
using ll = long long;

int n;
int arr[100010];
int cnt[1000010];

int main()
{
    int i, j;
    scanf("%d", &n);
    for(i=0;i<n;i++) scanf("%d", &arr[i]);
    int low = 0, high = 0;
    ll ans = 0;
    while(high < n) {
        cnt[arr[high]]++;
        if(cnt[arr[high]] >= 2) {
            while(cnt[arr[high]] >= 2) {
                cnt[arr[low++]]--;
                ans += (ll)(high - low + 1);
            }
        }
        high++;  
    }
    for(i=low;i<n;i++) {
        ans += (ll)(high) - (ll)(i);
    }
    printf("%lld", ans);
    return 0;
}