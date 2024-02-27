#include <stdio.h>
#include <vector>

using namespace std;

int prime[10010];
vector <int> v_prime;

void IsPrime()
{
	int i, j;
	for (i = 2; i <= 10000; i++) {
		if (prime[i] == 1) continue;
		for (j = i * 2; j <= 10000; j += i) {
			prime[j] = 1;
		}
	}
	for (i = 2; i <= 10000; i++) if (prime[i] == 0) v_prime.push_back(i);
	return;
}

int main()
{
	int i, j;
	int t;
	IsPrime();
	scanf("%d", &t);
	while (t--) {
		int x;
		scanf("%d", &x);
		int a, b;
		for (i = 0; i < v_prime.size(); i++) {
			if (x / 2 < v_prime[i]) break;
			if (prime[x - v_prime[i]] == 0) {
				a = v_prime[i];
				b = x - a;
			}
		}
		printf("%d %d\n", a, b);
	}
	return 0;
}