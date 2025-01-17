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
        if(s[s.size() - 1] == '0') printf("E\n");
        else printf("B\n");
    }
    return 0;
}