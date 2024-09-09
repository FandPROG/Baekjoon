#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

struct dat {
    ll a, b, t;
};

bool comp(dat x, dat y) {
    return x.t < y.t;
}

dat arr[200010];
int n;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        int i, j;
        int ansch = 0;
        scanf("%d", &n);
        for(i=0;i<n;i++) scanf("%lld", &arr[i].a);
        for(i=0;i<n;i++) scanf("%lld", &arr[i].b);
        for(i=0;i<n;i++) scanf("%lld", &arr[i].t);
        if(n == 1) {
            if(arr[0].t == 0) {
                printf("0\n");
                continue;
            }
            else {
                printf("-1\n");
                continue;
            }
        }
        sort(arr, arr + n, comp);
        ll min_val = 0, max_val = 2e15;
        for(i=0;i<n - 1;i++) {
            if(arr[i].t == arr[i + 1].t) continue;
            if(arr[i].a < arr[i + 1].a && arr[i].b > arr[i + 1].b) {
                min_val = max(min_val, ((arr[i + 1].a - arr[i].a) + (arr[i].b - arr[i + 1].b)) / (arr[i].b - arr[i + 1].b));
            }
            if(arr[i].a > arr[i + 1].a && arr[i].b < arr[i + 1].b) {
                if((arr[i].a - arr[i + 1].a) % (arr[i + 1].b - arr[i].b) == 0) {
                    max_val = min(max_val, (arr[i].a - arr[i + 1].a) / (arr[i + 1].b - arr[i].b) - 1);
                }
                else max_val = min(max_val, (arr[i].a - arr[i + 1].a) / (arr[i + 1].b - arr[i].b));
            }
            if(arr[i].a <= arr[i + 1].a && arr[i].b <= arr[i + 1].b) {
                ansch = 1;
                break;
            }
        }
        if(max_val < min_val || ansch == 1) {
            printf("-1\n");
            continue;
        }
        ll is_same_day = -1;
        for(i=0;i<n-1;i++) {
            if(arr[i].t == arr[i + 1].t) {
                ll res;
                if(arr[i].a == arr[i + 1].a) {
                    if(arr[i].b == arr[i + 1].b) continue;
                    else {
                        res = 0;
                    }
                }
                else if(arr[i].a < arr[i + 1].a && arr[i].b > arr[i + 1].b) {
                    if((arr[i + 1].a - arr[i].a) % (arr[i].b - arr[i + 1].b) == 0) {
                        res = ((arr[i + 1].a - arr[i].a) / (arr[i].b - arr[i + 1].b));
                    }
                    else {
                        ansch = 1;
                        break;
                    }
                }
                else if(arr[i].a > arr[i + 1].a && arr[i].b < arr[i + 1].b) {
                     if((arr[i].a - arr[i + 1].a) % (arr[i + 1].b - arr[i].b) == 0) {
                        res = ((arr[i].a - arr[i + 1].a) / (arr[i + 1].b - arr[i].b));
                    }
                    else {
                        ansch = 1;
                        break;
                    }
                }
                else {
                    ansch = 1;
                    break;
                }
                if(res < min_val || res > max_val) {
                    ansch = 1;
                    break;
                }
                if(is_same_day == -1) is_same_day = res;
                else {
                    if(is_same_day != res) {
                        ansch = 1;
                        break;
                    }
                }
            }
            else {
                is_same_day = -1;
            }
        }
        if(ansch == 1) {
            printf("-1\n");
            continue;
        }
        printf("%lld\n", min_val);
    }
    return 0;
}