#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using lD = long double;
using D = double;

vector <int> arr;
int groupCnt = 0;
vector <int> vec[200010];
vector <int> sum[200010];
vector <pair<int, int>> where;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i;
    int n, Q;
    cin >> n >> Q;
    for(i=0;i<n;i++) {
        string x;
        cin >> x;
        if(x == "false" || x == "or") arr.push_back(0);
        else if(x == "true" || x == "and") arr.push_back(1);
    }
    for(i=0;i<n;i++) {
        if(arr[i] == 0 && i % 2 == 1) {
            groupCnt++;
            where.push_back({-1, -1});
        }
        else {
            where.push_back({groupCnt, vec[groupCnt].size()});
            vec[groupCnt].push_back(arr[i]);
        }
    }
    groupCnt++;
    for(i=0;i<groupCnt;i++) {
        if(vec[i][0] == 0) sum[i].push_back(1);
        else sum[i].push_back(0);
        for(int j=1;j<vec[i].size();j++) {
            if(j % 2 == 0 && vec[i][j] == 0) sum[i].push_back(sum[i][j - 1] + 1);
            else sum[i].push_back(sum[i][j - 1]);
        }
    }
    vector <int> ans;
    if(sum[0][sum[0].size() - 1] == 0) ans.push_back(1);
    else ans.push_back(0);
    for(i=1;i<groupCnt;i++) {
        if(sum[i][sum[i].size() - 1] == 0) ans.push_back(ans[i - 1] + 1);
        else ans.push_back(ans[i - 1]);
    }
    int endans = ans[groupCnt - 1];
    vector <char> lastans;
    while(Q--) {
        int l, r;
        string s;
        cin >> l >> r >> s;
        l--;
        r--;
        int lgr = where[l].first, rgr = where[r].first;
        int lidx = where[l].second, ridx = where[r].second;
        if(lgr == rgr) {
            int endres = endans;
            int check = 0;
            if(sum[lgr][sum[lgr].size() - 1] == 0) endres--;
            if(endres == 0 && s == "false") check = 1;
            else if(endres > 0 && s == "true") check = 1;
            else {
                int res;
                if (lidx == 0) res = sum[lgr][ridx];
                else res = sum[lgr][ridx] - sum[lgr][lidx - 1];
                if(sum[lgr][sum[lgr].size() - 1] - res == 0) {
                    if(s == "true") check = 1;
                }
            }
            if(check == 1) lastans.push_back('Y');
            else lastans.push_back('N');
        }
        else {
            int endres = endans;
            int check = 0;
            if(lgr == 0) endres -= ans[rgr];
            else endres -= (ans[rgr] - ans[lgr - 1]);
            if(endres == 0 && s == "false") check = 1;
            else if(endres > 0 && s == "true") check = 1;
            else {
                int Lres, Rres = sum[rgr][sum[rgr].size() - 1] - sum[rgr][ridx];
                if(lidx == 0) Lres = 0;
                else Lres = sum[lgr][lidx - 1];
                if(Lres + Rres == 0 && s == "true") check = 1;
            }
            if(check == 1) lastans.push_back('Y');
            else lastans.push_back('N');
        }
    }
    for(auto printans : lastans) cout << printans;
    return 0;
}