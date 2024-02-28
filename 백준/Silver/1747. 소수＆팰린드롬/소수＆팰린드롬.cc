#include <stdio.h>
#include <vector>

using namespace std;

int prime[1100010];
vector <int> vec;
int n;

void IsPrime()
{
	int i, j;
	prime[2] = 1;
	for (i = 3; i <= 1100000; i++) {
		if (i % 2 == 0 || prime[i] == 1) continue;
		for (j = i * 2; j <= 1100000; j += i) {
			prime[j] = 1;
		}
	}
	if(n <= 2) vec.push_back(2);
	for (i = 3; i <= 1100000; i++) if (i >= n && i % 2 != 0 && prime[i] == 0) vec.push_back(i);
	return;
}

int main()
{
	int i, j;
	scanf("%d", &n);
	IsPrime();
	for (i = 0; i < vec.size(); i++) {
		vector <int> pel;
		int x = vec[i];
		while (x >= 1) {
			pel.push_back(x % 10);
			x /= 10;
		}
		int siz = pel.size();
		int ch = 0;
		for (j = 0; j < siz / 2; j++) {
			if (pel[j] != pel[siz - j - 1]) ch = 1;
		}
		if (ch == 0) {
			printf("%d", vec[i]);
			break;
		}
	}
	return 0;
}