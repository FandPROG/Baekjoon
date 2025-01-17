#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n % 4 == 0 || n % 4 == 2) cout << "SK\n";
    else cout << "CY\n";
    return 0;
}