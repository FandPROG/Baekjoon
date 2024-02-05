#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int n, m, s, ans;
vector<pair<int, int>> vec[5];

int main() 
{
    int i, j;
    scanf("%d %d %d", &n, &m, &s);
    for (i = 0; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        if (s > u) vec[0].push_back({ u,v });
        else vec[1].push_back({ u,v });
    }
    sort(vec[0].begin(), vec[0].end());
    sort(vec[1].begin(), vec[1].end());
    reverse(vec[1].begin(), vec[1].end());
    for (int k = 0; k < 2; k++) {
        for (i = 0; i < vec[k].size(); i++) {
            int cur = 0;
            for (j = i; j < vec[k].size(); j++) {
                int t = cur + vec[k][j].second;
                if (t >= m) {
                    vec[k][j].second = t - m;
                    cur = 0;
                    ans += 2 * abs(s - vec[k][i].first);
                    i = j;
                    if (t > m) i--;
                    break;
                }
                else {
                    cur += vec[k][j].second;
                }
                if (j == vec[k].size() - 1 && cur != 0) {
                    ans += 2 * abs(s - vec[k][i].first);
                    i = j;
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}