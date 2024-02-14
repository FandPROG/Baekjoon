#include <stdio.h>
#include <vector>

using namespace std;

int n, m;

int main()
{
	int i, j;
	while (1) {
		vector <int> vec;
		scanf("%d", &n);
		if (n == -1) break;
		int sum = 0;
		for (i = 1; i <= n; i++) {
			if (n != i && n % i == 0) {
				sum += i;
				vec.push_back(i);
			}
		}
		if (sum == n) {
			printf("%d = ", n);
			for (i = 0; i < vec.size(); i++) {
				printf("%d", vec[i]);
				if (vec.size() - 1 > i) printf(" + ");
			}
			printf("\n");
		}
		else printf("%d is NOT perfect.\n", n);
	}
	return 0;
}