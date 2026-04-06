#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    int rk = k + 1;
    int share = n / rk;
    int remain = n % rk;
    if(rk % 2 == 0) rk--;
    int res = share * (rk / 2);
    int oneres = share;
    //짝수 = 수가 (k + 1) / 2
    //1, 2, 3, 4, 5, 6
    //1, 2, 3, 4, 1
    //홀수 = 수가 (k + 2) / 2
    if(remain > 0) {
        if(remain % 2) {
            if(remain > (k + 1) / 2) {
                res += remain - ((k + 1) / 2);
            }
        }
        else {
            if(remain > (k + 1) / 2) {
                res += remain - ((k + 1) / 2);
            }
        }
    }
    int ans = 0;
    if(k % 2) {
        if(res >= k / 2 && oneres >= 1) ans = 1;
    }
    else if(res + (oneres / 2) >= k / 2) ans = 1;
    if(ans) cout << "YES";
    else cout << "NO";
    return 0;
}