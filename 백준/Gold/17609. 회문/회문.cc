#include <stdio.h>
#include <string.h>

int main()
{
	int i, j, t;
	scanf("%d", &t);
	while (t--) {
		char s[100010];
		int l;
		scanf("%s", s);
		l = strlen(s);
		int check = 0;
		int st = 0, ed = l - 1;
		while (st < ed) {
			if (s[st] != s[ed]) {
				if (s[st + 1] == s[ed]) {
					st++;
					if (check == 1) {
						check = 2;
						break;
					}
					check = 1;
				}
				else if (s[st] == s[ed - 1]) {
					ed--;
					if (check == 1) {
						check = 2;
						break;
					}
					check = 1;
				}
				else {
					check = 2;
					break;
				}
			}
			st++;
			ed--;
		}
		int check2 = 0;
		st = 0, ed = l - 1;
		while (st < ed) {
			if (s[st] != s[ed]) {
				if (s[st] == s[ed - 1]) {
					ed--;
					if (check2 == 1) {
						check2 = 2;
						break;
					}
					check2 = 1;
				}
				else if (s[st + 1] == s[ed]) {
					st++;
					if (check2 == 1) {
						check2 = 2;
						break;
					}
					check2 = 1;
				}
				else {
					check2 = 2;
					break;
				}
			}
			st++;
			ed--;
		}
		if (check == 1 || check2 == 1) check = 1;
		printf("%d\n", check);
	}
	return 0;
}