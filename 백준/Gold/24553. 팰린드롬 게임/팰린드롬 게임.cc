#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    int t;
    cin >> t;
    while(t--) {
        cin >> s;
        if(s[s.size() - 1] == '0') printf("1\n");
        else printf("0\n");
    }
    return 0;
}