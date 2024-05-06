#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> vec;
int n, ans;

int main()
{
    int i, j;
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        int x;
        scanf("%d", &x);
        vec.push_back(x);
    }
    i = 0;
    if(n >= 3) {
    for(i=0;i<n-2;i++) {
        if(vec[i] == 0) continue;
        vector <int> arr;
        int cnt = 0;
        for(j=0;j<3;j++) arr.push_back(vec[i + j]);
        for(j=0;j<3;j++) if(arr[j] > 0) cnt++;
        int a = arr[0], b = arr[1], c = arr[2];
        if(cnt == 3 && b > c) {
            if(a >= b -c) ans += 5 * (b-c), a -= (b-c), b -= (b-c);
            else ans += 5 * a, b -= a, a = 0;
        }
        //printf("%d %d %d -> ", a, b, c);
        arr[0] = a, arr[1] = b, arr[2] = c;
        cnt = 0;
        int mn = 2e9;
        for(j=0;j<3;j++) {
            if(arr[j] > 0) {
                cnt++;
                mn = min(mn, arr[j]);
            }
            else break;
        }
        for(j=0;j<cnt;j++) {
            if(arr[j] > 0) arr[j] -= mn;
        }
        if(cnt == 3) ans += (7*mn);
        if(cnt == 2) ans += (5*mn);
        if(cnt == 1) ans += (3*mn);
        vec[i] = arr[0], vec[i+1] = arr[1], vec[i+2] = arr[2];
        if(vec[i] > 0) ans += vec[i] * 3, vec[i] = 0;
        //printf("%d %d %d\n", vec[i], vec[i+1], vec[i+2]);
        arr.clear();
    }
    }
    if(n >= 2) {
        int cnt = 0;
        int mn = 2e9;
        for(j=0;j<2;j++) {
            if(vec[i + j] > 0) {
                cnt++;
                mn = min(mn, vec[i + j]);
            }
            else break;
        }
        for(j=0;j<cnt;j++) {
            if(vec[i + j] > 0) vec[i + j] -= mn;
        }
        if(cnt == 3) ans += (7*mn);
        if(cnt == 2) ans += (5*mn);
        if(vec[i] > 0) ans += vec[i] * 3, vec[i] = 0;
        i++;
    }
    if(n >= 1) {
        if(vec[i] > 0) ans += vec[i] * 3;
    }
    printf("%d", ans);
}