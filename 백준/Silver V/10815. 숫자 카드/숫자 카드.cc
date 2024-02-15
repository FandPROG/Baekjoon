#include <iostream>
#include <set>

using namespace std;

int n;
set <int> arr;

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		arr.insert(x);
	}
	int m;
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		if (arr.find(x) != arr.end()) printf("1 ");
		else printf("0 ");
	}
	return 0;
}