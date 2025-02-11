#include <stdio.h>
#include <string.h>

int main() {
	char s[100];
	scanf("%s", s);

	int ans[26];
	for (int i = 0;i < 26;i++)
		ans[i] = -1;
	for (int i = strlen(s) - 1;i >= 0;i--)
		ans[s[i] - 'a'] = i;
	for (int i = 0;i < 26;i++)
		printf("%d ", ans[i]);
}