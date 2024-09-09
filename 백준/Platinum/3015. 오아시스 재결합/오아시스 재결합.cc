#include <stdio.h>
#include <stack>

using namespace std;

int n;
long long ans;
stack <pair<int, int>> st;

int main()
{
    int i;
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        int x;
        scanf("%d", &x);
        int cnt = 1;
        while(!st.empty()) {
            int t = st.top().first;
            if(t < x) {
                ans += st.top().second;
                st.pop();
            }
            else break;
        }
        if(!st.empty()) {
            int t = st.top().first;
            if(t == x) {
                cnt = st.top().second + 1;
                ans += (cnt - 1);
                if(st.size() > 1) ans++;
                st.pop();
            }
            else {
                ans++;
            }
        }
        st.push({x, cnt});
    }
    printf("%lld", ans);
    return 0;
}