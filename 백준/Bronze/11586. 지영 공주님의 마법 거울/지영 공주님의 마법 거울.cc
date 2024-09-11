#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
int feel;
string s[110];

int main()
{
    int i, j;
    cin >> n;
    for(i=0;i<n;i++) {
        cin >> s[i];
    }
    cin >> feel;
    if(feel == 2) {
        for(i=0;i<n;i++) {
            reverse(s[i].begin(), s[i].end());
        }
    }
    if(feel == 3) {
        for(i=n - 1;i>=0;i--) {
            for(j=0;j<n;j++) {
                cout << s[i][j];
            }
            cout << '\n';
        }
        return 0;
    }
    for(i=0;i<n;i++) cout << s[i] << '\n';
    return 0;
}