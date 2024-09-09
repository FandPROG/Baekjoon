#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[25][25];
int ans;
int res[25][25];

struct dat {
    int x, y, val;
};

bool comp(dat x, dat y) {
    return x.val < y.val;
}

vector <dat> vec;

int main()
{
    int i, j, k;
    scanf("%d", &n);
    for(i=0;i<=n;i++) {
        for(j=0;j<=n;j++) {
            arr[i][j] = 1e9;
        }
    }
    for(i=1;i<=n;i++) {
        for(j=1;j<=n;j++) {
            scanf("%d", &res[i][j]);
            if(i < j) vec.push_back({i, j, res[i][j]});
        }
    }
    sort(vec.begin(), vec.end(), comp);
    for(int t=0;t<vec.size();t++) {
        int x = vec[t].x, y = vec[t].y, val = vec[t].val;
        if(arr[x][y] > val) {
            arr[x][y] = val;
            arr[y][x] = val;
            ans += val;
        }
        for(k=1;k<=n;k++) {
            for(i=1;i<=n;i++) {
                for(j=1;j<=n;j++) {
                    if(i == j) continue;
                    if(arr[i][j] > arr[i][k] + arr[k][j]) {
                        arr[i][j] = arr[i][k] + arr[k][j];
                    }
                }
            }
        }
    }
    for(i=1;i<=n;i++) {
        for(j=1;j<=n;j++) {
            if(i == j) continue;
            if(res[i][j] != arr[i][j]) {
                printf("-1");
                return 0;
            }
        }
    }
    printf("%d", ans);
    return 0;
}