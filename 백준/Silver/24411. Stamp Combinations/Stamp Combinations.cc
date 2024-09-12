#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

using ll = long long;

int n, q;
vector <int> vec;
vector <int> sum;

int main()
{
    int i, j;
    scanf("%d %d", &n, &q);
    vec.push_back(0);
    sum.push_back(0);
    for(i=0;i<n;i++) {
        int x;
        scanf("%d", &x);
        vec.push_back(x);
        sum.push_back(sum[i] + x);
    }
    vec.push_back(0);
    while(q--) {
        int x;
        scanf("%d", &x);
        int now = 0;
        int ch = 0;
        for(i=n + 1;i>=0;i--) {
            now += vec[i];
            if(now > x) break;
            int res_idx = lower_bound(sum.begin(), sum.end(), x - now) - sum.begin();
            if(sum[res_idx] + now == x && res_idx < i) {
                printf("Yes\n");
                ch = 1;
                break;
            }
        }
        if(ch == 0) printf("No\n");
    }
    return 0;
}