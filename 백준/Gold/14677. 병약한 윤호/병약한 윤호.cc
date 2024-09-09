#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int n;
char s[1510];
int ch[1510][1510];
int arr[1510];

struct dat{
    int x, y, cnt;
};

int main()
{
    int i;
    scanf("%d", &n);
    scanf("%s", s);
    for(i=0;i<n * 3;i++) {
        if(s[i] == 'B') arr[i] = 0;
        else if(s[i] == 'L') arr[i] = 1;
        else arr[i] = 2;
        //printf("%d ", arr[i]);
    }
    //printf("\n");
    queue <dat> q;
    q.push({0, n * 3 - 1, 0});
    ch[0][n * 3-1] = 1;
    int ans = 0;
    while(!q.empty()) {
        int ct = q.front().cnt;
        int st = q.front().x, ed = q.front().y;
        //printf("%d %d %d\n", st, ed, ct);
        q.pop();
        if(ct > ans) ans = ct;
        if(arr[st] == ct % 3 && st <= ed) {
            if(ch[st + 1][ed] == 0) {
                ch[st + 1][ed] = 1;
                q.push({st + 1, ed, ct + 1});
            }
        }
        if(arr[ed] == ct % 3 && st <= ed) {
            if(ch[st][ed - 1] == 0) {
                ch[st][ed - 1] = 1;
                q.push({st, ed - 1, ct + 1});
            }
        }
    }
    printf("%d", ans);
    return 0;
}