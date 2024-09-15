#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, k;
int arr[55][55];
int test[55][55];
vector <int> vec[55], vec2[55];

void fulltest()
{
    int i, j;
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            test[i][j] = arr[i][j];
        }
    }
}

void fulltest_line(int x)
{
    int i, j;
    for(i=0;i<n;i++) {
        if(test[i][x] == 1) test[i][x] = 0;
        else test[i][x] = 1;
    }
}

int test_res()
{
    int i, j;
    int res = 0;
    for(i=0;i<n;i++) {
        int cnt = 0;
        for(j=0;j<m;j++) {
            if(test[i][j] == 1) cnt++;
        }
        if(cnt == m) res++;
    }
    return res;
}

int main()
{
    int i, j;
    int ans = 0;
    scanf("%d %d", &n, &m);
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            scanf("%1d", &arr[i][j]);
            if(arr[i][j] == 0) vec[i].push_back(j);
            else vec2[i].push_back(j);
        }
    }
    scanf("%d", &k);
    if(k == 0) {
        fulltest();
        ans = test_res();
    }
    for(i=0;i<n;i++) {
        int vsz = vec[i].size();
        int v2sz = vec2[i].size();
        if(vsz > k) continue;
        if(vsz == 1 && k % 2 == 0) continue;
        if((vsz == 0 && k % 2 == 0) || (vsz > 0 && (k - vsz) % 2 == 0)) {
            fulltest();
            for(j=0;j<vsz;j++) {
                fulltest_line(vec[i][j]);
            }
            int res = test_res();
            ans = max(ans, res);
        }
    }
    printf("%d", ans);
    return 0;
}