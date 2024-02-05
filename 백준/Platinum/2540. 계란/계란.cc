#include <stdio.h>
#include <algorithm>

using namespace std;

int ans_cnt[5];
int ans_way[5][5][3010];

struct st {
	int num;
	int p; //1 = a, 2 = b, 3 = c, 4 = p
	int og;
};

bool compare(st a, st b)
{
	return a.num < b.num;
}

bool comp(st a, st b)
{
	return a.p < b.p;
}

int an[5];
st de[5];

void OddNumber()
{
	de[3].num--;
	de[2].num--;
	de[1].num += 2;
}

void case1() // A == 0 and B == 0
{
	de[2].num--;
	de[3].num--;
	de[1].num += 2;
}

void case2() // A + B < C
{
	de[1].num--;
	de[2].num--;
	de[0].num += 2;
}

void case3() // A + B >= C
{
	de[1].num--;
	de[2].num--;
	de[3].num += 2;
}

int allsum;

int main()
{
	int i, j;
	int x;
	scanf("%d", &x);
	for (i = 0; i < 4; i++) {
		scanf("%d", &an[i]);
		allsum += an[i];
	}
	for (i = 0; i < 4; i++) printf("%d ", an[i]);
	printf("\n");
	for (i = 0; i < 4; i++) {
		int sum = 0;
		for (j = 0; j < 4; j++) {
			if (j != i) sum += an[j];
			de[j].num = an[j];
			de[j].p = 0;
			de[j].og = j;
		}
		de[i].p = 4;
		sort(de, de + 4, compare);
		int ccnt = 1;
		for (j = 0; j < 4; j++) if (de[j].p != 4) de[j].p = ccnt++;
		if (sum % 2 == 1 && an[i] == 0) continue;
		sort(de, de + 4, comp);
		if (sum % 2 == 1) {
			OddNumber();
			for (j = 0; j < 4; j++) ans_way[i][de[j].og][ans_cnt[i]] = de[j].num;
			ans_cnt[i]++;
		}
		while (allsum > de[3].num) {
			sort(de, de + 4, compare);
			ccnt = 1;
			sum = 0;
			for (j = 0; j < 4; j++) {
				if (de[j].p != 4) {
					de[j].p = ccnt++;
					sum += de[j].num;
				}
			}
			sort(de, de + 4, comp);
			if (sum % 2 == 1) OddNumber();
			else if (de[0].num == 0 && de[1].num == 0) case1();
			else if (de[0].num + de[1].num < de[2].num) case2();
			else if (de[0].num + de[1].num >= de[2].num) case3();
			for (j = 0; j < 4; j++) ans_way[i][de[j].og][ans_cnt[i]] = de[j].num;
			ans_cnt[i]++;
		}
	}
	int min_ans = 2e9, ans_idx;
	for (i = 0; i < 4; i++) {
		if (min_ans > ans_cnt[i] && ans_cnt[i] != 0) {
			ans_idx = i;
			min_ans = ans_cnt[i];
		}
	}
	for (i = 0; i < ans_cnt[ans_idx]; i++) {
		for (j = 0; j < 4; j++) printf("%d ", ans_way[ans_idx][j][i]);
		printf("\n");
	}
	return 0;
}