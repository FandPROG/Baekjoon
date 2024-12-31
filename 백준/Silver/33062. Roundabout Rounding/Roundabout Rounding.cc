#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

ll P[11];

int main()
{
    int t;
    scanf("%d", &t);
    P[2] = 5;
    for(int i=3;i<=10;i++) {
        P[i] = P[i - 1];
        ll res = 0;
        for(int j = 0;j<i - 1;j++) {
            res += 4 * pow(10, j);
        }
        res++;
        P[i] += pow(10, i - 1) - res;
        //printf("%lld\n", (ll)pow(10, i - 1) - res);
    }
    while(t--) {
        int N;
        vector <int> vec;
        scanf("%d", &N);
        ll n = (ll)N;
        while(N >= 10) {
            vec.push_back(N % 10);
            N /= 10;
        }
        vec.push_back(N);
        reverse(vec.begin(), vec.end());
        ll ans = P[vec.size() - 1];
        ll res = 0;
        for(int i = 0;i<vec.size();i++) {
            res += (ll)(4 * pow(10, i));
        }
        if(vec[0] >= 5) {
            n = (ll)(5 * pow(10, vec.size() - 1));
            n--;
        }
        res++;
        if(res <= n) ans += (ll)(n - res + 1);
        printf("%lld\n", ans);
    }
    return 0;
}