#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int n;
vector <pair<int, int>> vec;
set <pair<int, int>> st;

int main()
{
    int i, j;
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        vec.push_back({x, y});
        st.insert({x, y});
    }
    int ans = 0;
    for(i=0;i<n - 1;i++) {
        for(j= i + 1;j<n;j++) {
            int x1 = vec[i].first, y1 = vec[i].second;
            int x2 = vec[j].first, y2 = vec[j].second;
            if(x1 == x2 || y1 == y2) continue;
            if(st.find({x1, y2}) != st.end() && st.find({x2, y1}) != st.end()) ans++;
        }
    }
    printf("%d", ans/2);
    return 0;
}