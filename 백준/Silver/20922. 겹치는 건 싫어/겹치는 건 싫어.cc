#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n, k;
vector <int> vec;
int cnt[100010];

int main()
{
    int i, j;
    scanf("%d %d", &n, &k);
    for(i=0;i<n;i++) {
        int x;
        scanf("%d", &x);
        vec.push_back(x);
    }
    int low = 0, high = 0;
    int ans = 0;
    while(high < n) {
        cnt[vec[high]]++;
        if(cnt[vec[high]] >= k) {
            while(cnt[vec[high]] > k) {
                cnt[vec[low++]]--;
            }
        }
        ans = max(ans, high - low + 1);
        high++;
    }
    printf("%d", ans);
    return 0;
}