#include <stdio.h>

int n;
int arr[1000010];
int res[1000010];

void Merge(int low, int mid, int high) {
	int i;
	
	int res_len = 0;
	int pointer_first = low;
	int pointer_second = mid + 1;

	while (pointer_first <= mid && pointer_second <= high) {
		if (arr[pointer_first] < arr[pointer_second]) {
			res[res_len++] = arr[pointer_first++];
		}
		else {
			res[res_len++] = arr[pointer_second++];
		}
	}
	if (pointer_first > mid) {
		for (i = pointer_second; i <= high; i++) {
			res[res_len++] = arr[i];
		}
	}
	else if (pointer_second > high) {
		for (i = pointer_first; i <= mid; i++) {
			res[res_len++] = arr[i];
		}
	}
	for (i = low; i <= high; i++) {
		arr[i] = res[i - low];
	}
	return;
}

void Merge_sort(int low, int high) {
	int mid = (low + high) / 2;
	if (low >= high) return;
	Merge_sort(low, mid);
	Merge_sort(mid + 1, high);
	Merge(low, mid, high);
}

int main()
{
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &arr[i]);
	Merge_sort(0, n - 1);
	for (i = 0; i < n; i++) printf("%d\n", arr[i]);
	return 0;
}