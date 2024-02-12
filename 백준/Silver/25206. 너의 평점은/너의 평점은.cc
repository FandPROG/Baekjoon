#include <stdio.h>

char name[60];
char grade[10];

int main() 
{
    int i, j;
    double db, sum = 0.0, alp, res = 0.0;
    for (i = 0; i < 20; i++) {
        scanf("%s %lf %s", name, &db, grade);
        if (grade[0] == 'P') continue;
        sum += db;
        if (grade[0] == 'F') continue;
        if (grade[0] == 'A') alp = 4;
        else if (grade[0] == 'B') alp = 3;
        else if (grade[0] == 'C') alp = 2;
        else alp = 1;
        if (grade[1] == '+') alp += 0.5;
        res += db * alp;
    }
    printf("%lf", res / sum);
    return 0;
}