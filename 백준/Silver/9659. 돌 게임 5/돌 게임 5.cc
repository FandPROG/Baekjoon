#include <iostream>
#include <string>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    if(n % 4 == 0 || n % 4 == 2) cout << "CY\n";
    else cout << "SK\n";
    return 0;
}