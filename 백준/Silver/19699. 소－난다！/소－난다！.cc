#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int IsPrime[10000];
vector <int> H, prime, ans;
bool check[1010];
int res = 0;

void GetAns(int x, int st)
{
    int i, j;
    if(x >= m) {
        bool primeCheck = 0;
        for(i=0;i<prime.size();i++) {
            if(prime[i] >= res) break;
            if(res % prime[i] == 0) {
                primeCheck = 1;
                break;
            }
        }
        if(!primeCheck) ans.push_back(res);
        return;
    }
    for(i=st;i<n;i++) {
        if(check[i] == 1) continue;
        check[i] = 1;
        res += H[i];
        GetAns(x + 1, i + 1);
        res -= H[i];
        check[i] = 0;
    }
    return;
}

int main()
{
    int i, j;
    scanf("%d %d", &n, &m);
    for(i=0;i<n;i++) {
        int x;
        scanf("%d", &x);
        H.push_back(x);
    }
    sort(H.begin(), H.end());
    int sum = 0;
    for(i=1;i<=m;i++) sum += H[n-i];
    for(i=2;i<=sum;i++) {
        if(IsPrime[i] == 1) continue;
        prime.push_back(i);
        for(j=i * 2;j<=sum;j+= i) {
            if(IsPrime[j] == 1) continue;
            IsPrime[j] = 1;
        }
    }
    GetAns(0, 0);
    sort(ans.begin(), ans.end());
    if(ans.size() == 0) printf("-1"); 
    else {
        printf("%d ", ans[0]);
        for(i=1;i<ans.size();i++) {
            if(ans[i] == ans[i - 1]) continue;
            else {
                printf("%d ", ans[i]);
            }
        }
    }
    return 0;
}