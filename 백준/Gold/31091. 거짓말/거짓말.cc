#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int arr[500010];
int minus_cnt[500010];
int plus_cnt[500010];
int minus_sum[500010];
int plus_sum[500010];

int main()
{
    int i, j;
    int n;
    scanf("%d", &n);
    vector <int> vec;
    for(i=0;i<n;i++) {
        int x;
        scanf("%d", &x);
        vec.push_back(x);
        if(x > 0) plus_cnt[x]++;
        else minus_cnt[(-1) * x]++;
    }
    plus_sum[0] = plus_cnt[0];
    for(i=1;i<=n;i++) {
        plus_sum[i] = plus_sum[i - 1] + plus_cnt[i];
    }
    minus_sum[0] = minus_cnt[0];
    for(i=1;i<=n;i++) {
        minus_sum[i] = minus_cnt[i] + minus_sum[i - 1];
    }
    int ans = 0;
    vector <int> res;
    for(i=0;i<=n;i++) {
        int up = plus_sum[n] - plus_sum[i];
        int down = minus_sum[i] - minus_cnt[i];
        if(down + up == i) {
            ans++;
            res.push_back(i);
            continue;
        }
    }
    printf("%d\n", ans);
    for(i=0;i<res.size();i++) printf("%d ", res[i]);
    return 0;
}