#include <stdio.h>

long long w, h, x, y, t;

int main()
{
	scanf("%lld %lld %lld %lld %lld", &w, &h, &x, &y, &t);
	x += t;
	y += t;
	long long ans_x, ans_y;
	if (x <= w) ans_x = x;
	else {
		long long divi = x / w;
		if (divi % 2) ans_x = w - (x % w); //홀수
		else ans_x = x % w; //짝수
	}
	if (y <= w) ans_y = y;
	else {
		long long divi = y / h;
		if (divi % 2) ans_y = h - (y % h); //홀수
		else ans_y = y % h; //짝수
	}
	printf("%lld %lld", ans_x, ans_y);
	return 0;
}