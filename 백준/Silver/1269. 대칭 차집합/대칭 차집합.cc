#include <stdio.h>
#include <vector>
#include <set>

using namespace std;

int n, m;
vector <int> a, b;
set<int> st1, st2;

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		st1.insert(x);
		a.push_back(x);
	}
	for (i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		st2.insert(x);
		b.push_back(x);
	}
	for (i = 0; i < n; i++) {
		if (st2.find(a[i]) == st2.end()) continue;
		st2.erase(a[i]);
	}
	for (i = 0; i < m; i++) {
		if (st1.find(b[i]) == st1.end()) continue;
		st1.erase(b[i]);
	}
	printf("%d", st1.size() + st2.size());
	return 0;
}