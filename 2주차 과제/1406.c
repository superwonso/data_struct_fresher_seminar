#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
	char a[100023];
	int m;
	scanf("%s", a);
	scanf("%d", &m);

	int len = strlen(a);
	int c = len;

	char cuser[3];
	for (int i = 0;i < m;i++) {
		scanf("%s", cuser);

		if (cuser[0] == 'L') {
			if (c > 0) c--;
		}
		else if (cuser[0] == 'D') {
			if (c < len) c++;
		}
		else if (cuser[0] == 'B') {
			if (c > 0) {
				memmove(&a[c - 1], &a[c], len - c + 1);
				c--;
				len--;
			}
		}
		else if (cuser[0] == 'P') {
			char ch;
			scanf(" %c", &ch);
			memmove(&a[c + 1], &a[c], len - c + 1);
			a[c] = ch;
			c++;
			len++;
		}
	}
	printf("%s\n", a);
	return 0;

}

