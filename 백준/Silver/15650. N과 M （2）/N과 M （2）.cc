#include <stdio.h>

int n, m;
int d[10], check[10];

void MNM(int N, int s) {
    int i, a;
    if(N == m) {
		for(i=0;i<m;i++) {
			printf("%d ", d[i]);
		}
		printf("\n");
		return;
	}
    for(i=s;i<=n;i++) {
        if(check[i] == 0) {
            check[i] = 1;
            d[N] = i;    
            MNM(N+1, i+1);
            check[i] = 0;
        }
    }
}
int main() {
    scanf("%d %d", &n, &m);
    MNM(0, 1);
    return 0;
}