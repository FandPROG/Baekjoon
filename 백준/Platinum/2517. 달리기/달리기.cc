#include <stdio.h>

struct dt {
	int skill, idx, ans;
};
int n;
int ans[1000010];
dt v[1000010], tp[1000010];

void merge(dt* left, int n1, dt* right, int n2)
{
	int acc = 0, a = 0, b = 0, k = 0;
	while (a < n1 || b < n2) {
		if (a < n1 && (b == n2 || left[a].skill < right[b].skill)) {
			tp[k] = left[a++];
		}
		else {
			tp[k] = right[b++];
			tp[k].ans += n1 - a;
		}
		k++;
	}
	for (k = 0; k < n1 + n2; k++) left[k] = tp[k];
}

void mergesort(dt* p, int n)
{
	if (n == 1) return;
	mergesort(p, n / 2);
	mergesort(p + n / 2, (n + 1) / 2);
	merge(p, n / 2, p + n / 2, (n + 1) / 2);
}

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &v[i].skill);
		v[i].idx = i;
	}
	mergesort(v, n);
	for (i = 0; i < n; i++) ans[v[i].idx] = v[i].ans;
	for (i = 0; i < n; i++) printf("%d\n", ans[i] + 1);
	return 0;
}