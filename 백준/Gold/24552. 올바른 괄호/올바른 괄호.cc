#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

char s[100010];
int l;

int main()
{
    int i, j;
    scanf("%s", s);
    l = strlen(s);
    int sum = 0;
    int left = 0, right = 0;
    for (i=0;i<l;i++) {
        if(s[i] == '(') {
            left++;
            sum++;
        }
        else {
            right++;
            sum--;
        }
        if(sum < 0) {
            printf("%d", right);
            return 0;
        }
        if(sum == 0) {
            left = 0;
        }
    }
    printf("%d", left);
    return 0;
}