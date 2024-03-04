#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[25];

int main()
{
	int i;
	for (i = 1; i <= 20; i++) arr[i] = i;
	for (i = 0; i < 10; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		reverse(arr + x, arr + 1 + y);
	}
	for (i = 1; i <= 20; i++) printf("%d ", arr[i]);
	return 0;
}