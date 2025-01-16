#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

char s[200010];
ll arr[200010];

int main()
{
    //freopen("input.txt", "r", stdin);  
    ll i, j;
    ll n, m;
    scanf("%lld %lld", &n, &m);
    scanf("%s", s);
    ll sum = 0;
    for(i=0;i<n;i++) {
        scanf("%lld", &arr[i]);
        sum += arr[i];
    }
    ll RLcnt = 0;
    for(i=0;i<n - 1;i++) {
        if(s[i] == 'R' && s[i + 1] == 'L') {
            s[i] = '.';
            s[i + 1] = '.';
            RLcnt++;
        }
    }
    if(s[0] == 'L' && s[n - 1] == 'R') {
        s[0] = '.';
        s[n - 1] = '.';
        RLcnt++;
    }
    //printf("%s\n", s);
    vector <pair<ll, char>> cows;
    pair<ll, char> ch = {0, '.'};
    for(i=0;i<n;i++) {
        if(s[i] != '.') {
            if(ch.second != s[i] && ch.second != '.') {
                cows.push_back(ch);
                ch.first = arr[i];
                ch.second = s[i];
                continue;
            }
            ch.first += arr[i];
            ch.second = s[i];
        }
        else {
            if(ch.first == 0) continue;
            cows.push_back(ch);
            ch.first = 0;
            ch.second = '.';
        }
    }
    if(ch.first > 0) cows.push_back(ch);
    ll endcow = cows.size() - 1;
    if(endcow > 0) {
        if(cows[0].second == 'L' && cows[endcow].second == 'L' && (s[0] == 'L' && s[n-1] == 'L')) {
            cows[endcow].first += cows[0].first;
            cows[0].second = 'E';
        }
        if(cows[0].second == 'R' && cows[endcow].second == 'R' && (s[0] == 'R' && s[n-1] == 'R')) {
            cows[0].first += cows[endcow].first;
            cows[endcow].second = 'E';
        }
    }
    ll ans = 0;
    for(auto i : cows) {
        if(i.second == 'E') continue;
        else {
            ans += min(i.first, (ll)m);
        }
    }
    if(RLcnt == 0) printf("%lld", sum);
    else printf("%lld", sum - ans);
    return 0;
}