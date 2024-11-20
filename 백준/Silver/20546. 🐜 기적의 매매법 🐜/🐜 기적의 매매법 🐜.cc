#include <stdio.h>

int n;
int arr[1010];
int timing[1010]; //-1->매수타이밍, 1 -> 매도타이밍


int main()
{
    int i, j;
    scanf("%d", &n);
    scanf("%d", &arr[0]);
    int pt = 0, mt = 0;
    for(i=1;i<14;i++) {
        scanf("%d", &arr[i]);
        if(arr[i - 1] < arr[i]) {
            pt++;
            if(pt >= 3) timing[i] = 1;
        }
        else pt = 0;
        if(arr[i-1] > arr[i]) {
            mt++;
            if(mt >= 3) timing[i] = -1;
        }
        else mt = 0;
    }
    int Bstock = 0, Tstock = 0;
    int Bm = n, Tm = n;
    for(i=0;i<14;i++) {
        if(Bm >= arr[i]) {
            Bstock += Bm / arr[i];
            Bm = Bm % arr[i];
        }
        if(timing[i] == 1) {
            Tm += Tstock * arr[i];
            Tstock = 0;
        }
        if(timing[i] == -1) {
            Tstock += (Tm / arr[i]);
            Tm = Tm % arr[i];
        }
    }
    Tm += Tstock * arr[13];
    Bm += Bstock * arr[13];
    if(Tm < Bm) printf("BNP");
    else if(Tm > Bm) printf("TIMING");
    else printf("SAMESAME");
    return 0;
}