#include <stdio.h>
#include <algorithm>

using namespace  std;

int n, k;

int main()
{
    int i, j;
    scanf("%d %d", &n, &k);
    for(i=0;i<k;i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if(x == y) {
            printf("1\n");
        }
        else if(x < y) {
            int turn = n - y; // x남은 턴의 수
            if(x + turn >= y - 1) {
                printf("1\n");
            }
            else {
                printf("0\n");
            }
        }
        else {
            int turn = n - x + 1;
            if(y + turn >= x - 1) printf("1\n");
            else printf("0\n");
        }
    }
    return 0;
}