#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int i, j;
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        vector <int> vec(n);
        for(i=0;i<n;i++) scanf("%d", &vec[i]);
        set <int> ans;
        if(n < 3) {
            if(vec[0] == vec[1]) ans.insert(vec[0]);
        }
        else {
            for(i=0;i<n - 2;i++) {
                if(vec[i] == vec[i + 1] || vec[i] == vec[i + 2]) ans.insert(vec[i]);
                else if(vec[i + 1] == vec[i + 2]) ans.insert(vec[i + 1]);
            }
        }
        if(ans.size() == 0) printf("-1\n");
        else {
            for(auto itr = ans.begin(); itr != ans.end();itr++) {
                printf("%d ", *itr);
            }
            printf("\n");
        }
    }
    return 0;
}
