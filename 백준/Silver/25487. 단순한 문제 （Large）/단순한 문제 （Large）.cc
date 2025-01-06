#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        printf("%d\n", min(a, min(b, c)));
    }
}