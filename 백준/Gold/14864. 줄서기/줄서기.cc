#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int ans[100010];
bool check[100010];
vector <pair<int, int>> vec;

int main()
{
    int i, j;
    scanf("%d %d", &n, &m);
    for(i=1;i<=n;i++) ans[i] = i;
    for(i=0;i<m;i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        vec.push_back({x, y});
        ans[x]++;
        ans[y]--;
    }
    for(i=0;i<m;i++) {
        int x = vec[i].first, y = vec[i].second;
        if(ans[x] <= ans[y]) {
            printf("-1");
            return 0;
        }
    }
    for(i=1;i<=n;i++) {
        if(check[ans[i]] == 1) {
            printf("-1");
            return 0;
        }
        check[ans[i]] = 1;
    }
    for(i=1;i<=n;i++) printf("%d ", ans[i]);
    return 0;
}