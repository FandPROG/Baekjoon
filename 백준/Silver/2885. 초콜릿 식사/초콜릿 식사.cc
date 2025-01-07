#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int k;
vector <int> arr;

int main()
{
    int i, j;
    scanf("%d", &k);
    arr.push_back(1);
    while(1) {
        int res = arr.back();
        if(res * 2 >= k) break;
        else {
            arr.push_back(res * 2);
        }
    }
    printf("%d", arr.back() * 2);
    for(i=0;i<arr.size();i++) {
        int res = arr[arr.size() - i - 1];
        if(k >= res) k -= res;
        if(k == 0) {
            printf(" %d", i + 1);
            return 0;
        }
    }
    printf(" 0");
    return 0;
}