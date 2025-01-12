#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
using d = double;

int n;

struct dat{
    d x, y, vx, vy;
};

vector <dat> vec;

d func(d t)
{
    int i, j;
    d minx = 2e9, miny = 2e9, maxx = -2e9, maxy = -2e9;
    for(i=0;i<n;i++) {
        d xi = vec[i].x + (vec[i].vx * t), yi = vec[i].y + (vec[i].vy * t);
        minx = min(minx, xi);
        miny = min(miny, yi);
        maxx = max(maxx, xi);
        maxy = max(maxy, yi);
    }
    return max(maxx - minx, maxy - miny);
}

int main()
{
    int i, j;
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        d x, y, vx, vy;
        scanf("%lf %lf %lf %lf", &x, &y, &vx, &vy);
        vec.push_back({x, y, vx, vy});
    }
    d low = 0, high = 2000;
    while(high - low > 1e-12) {
        d p = (low * 2.0 + high) / 3.0, q = (low + high * 2.0) / 3.0;
        if(func(p) < func(q)) high = q;
        else low = p;
    }
    printf("%.11lf", func(low));
    return 0;
}