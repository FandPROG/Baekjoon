#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    vector <int> c(n), t(n);
    for(int i=0;i<n;i++) scanf("%d", &t[i]);
    for(int i=0;i<n;i++) scanf("%d", &c[i]);
    vector <int> res;
    for(int i=0;i<n;i++) res.push_back(t[i] - c[i]);
    sort(res.begin(), res.end());
    while(q--) {
        int v, s;
        scanf("%d %d", &v, &s);
        int s_idx = lower_bound(res.begin(), res.end(), s + 1) - res.begin();
        if(n - s_idx >= v) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}