#include <stdio.h>
#include <algorithm>

using namespace std;

long long ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
	return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}

int main()
{
	pair<long long, long long> p, p2, p3, p4;
	scanf("%lld %lld %lld %lld", &p.first, &p.second, &p2.first, &p2.second);
	scanf("%lld %lld %lld %lld", &p3.first, &p3.second, &p4.first, &p4.second);
	long long a = ccw(p.first, p.second, p2.first, p2.second, p3.first, p3.second);
	long long b = ccw(p.first, p.second, p2.first, p2.second, p4.first, p4.second);
	int ch = 0;
	if (a <= 0 && b >= 0) ch = 1;
	if (a >= 0 && b <= 0) ch = 1;
	long long c = ccw(p3.first, p3.second, p4.first, p4.second, p.first, p.second);
	long long d = ccw(p3.first, p3.second, p4.first, p4.second, p2.first, p2.second);
	int ch2 = 0;
	if (c >= 0 && d <= 0) ch2 = 1;
	if (c <= 0 && d >= 0) ch2 = 1;
	if ((a == 0 || b == 0) && (c == 0 || d == 0)) {
		if (p > p2) {
			pair<long long, long long> imsi = p;
			p = p2;
			p2 = imsi;
		}
		if (p3 > p4) {
			pair<long long, long long> imsi = p4;
			p4 = p3;
			p3 = imsi;
		}
		if (p3 <= p2 && p <= p4) printf("1");
		else printf("0");
	}
	else if (ch == 1 && ch2 == 1) printf("1");
	else printf("0");
}