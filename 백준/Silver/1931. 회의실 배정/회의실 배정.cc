#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector <pair<int, int>> vec;

int main()
{
    int i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        vec.push_back({ y, x });
    }
    sort(vec.begin(), vec.end());
    int end_time = 0, ans = 0;
    for (i = 0; i < n; i++) {
        if (end_time <= vec[i].second) {
            end_time = vec[i].first;
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}