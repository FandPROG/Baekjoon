#include <stdio.h>
#include <algorithm>
#include <stack>

using namespace std;

int n;
stack <pair<int, int>> st;
int ans[1000010], arr[1000010];
int cnt[10000010];

int main()
{
    int i, j;
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        scanf("%d", &arr[i]);
        cnt[arr[i]]++;
    }
    for(i=0;i<n;i++) {
        int x = arr[i];
        if(st.empty()) st.push({x, i});
        else {
            while(!st.empty()) {
                int t = st.top().first;
                if(cnt[t] < cnt[x]) {
                    int sec = st.top().second;
                    ans[sec] = x;
                    st.pop();
                }
                else break;
            }
            st.push({x, i});
        }
    }
    while(!st.empty()) {
        ans[st.top().second] = -1;
        st.pop();
    }
    for(i=0;i<n;i++) printf("%d ", ans[i]);
    return 0;
}