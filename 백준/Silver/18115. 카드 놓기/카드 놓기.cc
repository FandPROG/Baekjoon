#include <stdio.h>
#include <deque>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    deque <int> ans;
    int num = 1;
    vector<int> arr(n);
    for(int i=0;i<n;i++) scanf("%d", &arr[i]);
    for(int i=n - 1;i>=0;i--) {
        int x = arr[i];
        if(x == 1) {
            ans.push_front(num);
        }
        else if(x == 2) {
            ans.insert(ans.begin() + 1, num);
        }
        else {
            ans.push_back(num);
        }
        num++;
    }
    for(int i=0;i<ans.size();i++) printf("%d ", ans[i]);
    return 0;
}