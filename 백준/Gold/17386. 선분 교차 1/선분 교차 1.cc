#include <stdio.h>

long long ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
	return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}

int main()
{
	long long L1x1, L1x2, L1y1, L1y2;
	long long L2x1, L2x2, L2y1, L2y2;
	scanf("%lld %lld %lld %lld", &L1x1, &L1y1, &L1x2, &L1y2);
	scanf("%lld %lld %lld %lld", &L2x1, &L2y1, &L2x2, &L2y2);
	long long a = ccw(L1x1, L1y1, L1x2, L1y2, L2x1, L2y1);
	long long b = ccw(L1x1, L1y1, L1x2, L1y2, L2x2, L2y2);
	int ch = 0;
	if (a < 0 && b > 0) ch = 1;
	if (a > 0 && b < 0) ch = 1;
	long long c = ccw(L2x1, L2y1, L2x2, L2y2, L1x1, L1y1);
	long long d = ccw(L2x1, L2y1, L2x2, L2y2, L1x2, L1y2);
	int ch2 = 0;
	if (c > 0 && d < 0) ch2 = 1;
	if (c < 0 && d > 0) ch2 = 1;
	if (ch == 1 && ch2 == 1) printf("1");
	else printf("0");
}