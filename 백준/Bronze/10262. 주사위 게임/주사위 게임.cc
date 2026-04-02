#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector <int> st(4), ed(4);
    for(int i=0;i<4;i++) cin >> st[i] >> ed[i];
    int Ecnt = 0;
    for(int i=st[0];i<=ed[0];i++) {
        for(int j=st[1];j<=ed[1];j++) {
            for(int k=st[2];k<=ed[2];k++) {
                int res = i + j - k;
                if (res < st[3]) Ecnt += ed[3] - st[3] + 1;
                else if (res < ed[3]) Ecnt += ed[3] - res;
            }
        }
    }
    int Gcnt = 0;
    for(int i=st[2];i<=ed[2];i++) {
        for(int j=st[3];j<=ed[3];j++) {
            for(int k=st[1];k<=ed[1];k++) {
                int res = i + j - k;
                if (res < st[0]) Gcnt += ed[0] - st[0] + 1;
                else if (res < ed[0]) Gcnt += ed[0] - res;
            }
        }
    }
    if(Ecnt == Gcnt) cout << "Tie";
    else cout << ((Ecnt < Gcnt) ? "Gunnar" : "Emma");
    return 0;
}