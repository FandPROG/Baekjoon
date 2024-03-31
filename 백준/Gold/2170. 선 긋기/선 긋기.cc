#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int ans;
vector <pair<int, int>> vec;

int main()
{
    int i, j;
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        vec.push_back({x, y});
    }
    sort(vec.begin(), vec.end());
    int e = vec[0].second;
    int s = vec[0].first;
    for(i=1;i<n;i++) {
        if(e < vec[i].first) {
            ans += e - s;
            e = vec[i].second;
            s = vec[i].first;
        }
        else if(s <= vec[i].first && e >= vec[i].first && vec[i].second > e) {
            e = vec[i].second;
        }
    }
    ans += e - s;
    printf("%d", ans);
    return 0;
}