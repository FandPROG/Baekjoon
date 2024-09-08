#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int arr[300010];
vector<int> vec;

int main()
{
    int i, j;
    scanf("%d", &n);
    for(i=0;i<n;i++) scanf("%1d", &arr[i]);
    int now_num = arr[0];
    int count = 0;
    if(now_num == 1) count++;
    for(i=1;i<n;i++) {
        if(arr[i] == 0) {
            if(now_num == 1) {
                vec.push_back(count);
                count = 0;
                now_num = 0;
            }
            else {
                count = 0;
            }
        }
        if(arr[i] == 1) {
            now_num = 1;
            count++;
        }
    }
    if(count > 0) vec.push_back(count);
    int min_edge = 2e9;
    int vsz = vec.size();
    int st = 0, ed = vsz;
    if(arr[0] == 1) {
        min_edge = min(min_edge, vec[0] * 2 - 1);
        st++;
    }
    if(arr[n - 1] == 1) {
        min_edge = min(min_edge, vec[vsz - 1] * 2 - 1);
        ed--;
    }
    int min_odd = 2e9; // 홀수 min
    int min_even = 2e9; //짝수 min
    for(i=st;i<ed;i++) {
        if(vec[i] % 2) {
            min_odd = min(min_odd, vec[i]);
        }
        else {
            min_even = min(min_even, vec[i]);
        }
    }
    int Day = min(min_edge, min(min_odd, min_even - 1));
    int ans = 0;
    for(i=0;i<vsz;i++) {
        ans += (vec[i] + Day - 1) / Day; //올림을 위해 더함
    }
    printf("%d", ans);
    return 0;
}