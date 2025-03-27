#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll comb(int n,int k){
    if(k==0)return 1;
    if(k==1)return n;
    if(k==2)return (ll)n*(n-1)/2;
    if(k==3)return (ll)n*(n-1)*(n-2)/6;
    if(k==4)return (ll)n*(n-1)*(n-2)*(n-3)/24;
    return 0LL;
}

bool canMeld(vector<int> & cnt) {
    int sum=0;
    for(int i=1;i<=9;i++) {
        sum += cnt[i];
    }
    if(sum==0) return true;
    int i;
    for(i=1;i<=9;i++) {
        if(cnt[i]>0) break;
    }
    if(cnt[i]>=3){
        cnt[i]-=3;
        if(canMeld(cnt)){
            cnt[i]+=3;
            return true;
        }
        cnt[i]+=3;
    }
    if(i<=7 && cnt[i]>0 && cnt[i+1]>0 && cnt[i+2]>0){
        cnt[i]--; cnt[i+1]--; cnt[i+2]--;
        if(canMeld(cnt)){
            cnt[i]++; cnt[i+1]++; cnt[i+2]++;
            return true;
        }
        cnt[i]++; cnt[i+1]++; cnt[i+2]++;
    }
    return false;
}

bool isWinning(const vector<int> & hand) {
    int total=0;
    for(int i=1;i<=9;i++) {
        total += hand[i];
    }
    if(total!=14) return false;
    bool sevenPairs=true;
    int cntPairs=0;
    for(int i=1;i<=9;i++) {
        if(hand[i]!=0 && hand[i]!=2) {
            sevenPairs=false;
            break;
        }
        if(hand[i]==2) cntPairs++;
    }
    if(sevenPairs && cntPairs==7) return true;
    for(int i=1;i<=9;i++) {
        if(hand[i]>=2) {
            vector<int> tmp = hand;
            tmp[i]-=2;
            if(canMeld(tmp)) return true;
        }
    }
    return false;
}

vector<int> freq;
vector<int> hand;
ll ans = 0;

void dfs(int d,int sum) {
    if(d==10){
        if(sum==14){
            if(isWinning(hand)) {
                ll waysLocal=1;
                for(int i=1;i<=9;i++) {
                    waysLocal *= comb(freq[i],hand[i]);
                }
                ans += waysLocal;
            }
        }
        return;
    }
    for(int k=0;k<=freq[d] && sum+k<=14;k++){
        hand[d] = k;
        dfs(d+1,sum+k);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> tiles(N);
    for(int i=0;i<N;i++) {
        cin >> tiles[i];
    }
    freq.assign(10,0);
    for(int a : tiles) {
        freq[a]++;
    }
    hand.assign(10,0);
    dfs(1,0);
    cout << ans;
    return 0;
}
