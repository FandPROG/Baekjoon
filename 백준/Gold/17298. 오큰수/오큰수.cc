#include <stdio.h>
#include <stack>

using namespace std;

int n;
int ans[1000010];
stack <pair<int, int>> st;

int main()
{
    int i;
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        int x;
        scanf("%d", &x);
        if(st.empty()) st.push({i, x});
        else {
            while(!st.empty()) {
                int t = st.top().second;
                if(t < x) {
                    int idx = st.top().first;
                    ans[idx] = x;
                    st.pop();
                }
                else {
                    break;
                }
            }
            st.push({i, x});
        }
    }
    while(!st.empty()) {
        int idx = st.top().first;
        ans[idx] = -1;
        st.pop();
    }
    for(i=0;i<n;i++) printf("%d ", ans[i]);
    return 0;
}