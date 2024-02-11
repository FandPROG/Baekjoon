#include <stdio.h>

int arr[10];
int ans[10] = { 1, 1, 2, 2, 2, 8 };

int main()
{
	int i, j;
	for (i = 0; i < 6; i++) scanf("%d", &arr[i]);
	for (i = 0; i < 6; i++) printf("%d ", ans[i] - arr[i]);
	return 0;
}