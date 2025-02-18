#include <stdio.h>
#include <stdlib.h>

#define MAX_length 100000

void editor(char cmd, char arg, int* cur, char* word) {
	int temp;
	switch (cmd) {
	case 'L':
		*cur -= 1;
		if (*cur < -1)
			*cur = -1;
		break;
	case 'D':
		*cur += 1;
		if (*cur > strlen(word) - 1)
			*cur = strlen(word) - 1;
		break;
	case 'B':
		if (*cur <= -1)
			break;
		else if (*cur == strlen(word) - 1) {
			word[*cur] = '\0';
			*cur -= 1;
		}
		else {
			for (int i = *cur + 1; i < (int)strlen(word); i++) {
				word[i - 1] = word[i];
			}
			word[strlen(word) - 1] = '\0';
			*cur -= 1;
		}
		break;
	case 'P':
		if (*cur == strlen(word) - 1) {
			word[*cur + 1] = arg;
			word[*cur + 2] = '\0';
			*cur += 1;
		}
		else if (*cur == 0) {
			for (int i = (int)strlen(word); i >= *cur; i--) {
				word[i + 1] = word[i];
			}
			word[*cur] = arg;
			*cur = 0;
		}
		else {
			for (int i = (int)strlen(word); i >= *cur + 1; i--) {
				word[i + 1] = word[i];
			}
			word[*cur + 1] = arg;
			*cur += 1;
		}
	}
}


int main()
{
	char word[MAX_length];
	fgets(word, MAX_length, stdin);
	word[strcspn(word, "\n")] = '\0';

	int time;
	scanf("%d", &time);
	getchar();

	int cur = strlen(word) - 1;

	char cmd, arg;
	for (int i = 0; i < time; i++) {
		scanf("%c", &cmd);
		getchar();

		if (cmd == 'P') {
			scanf(" %c", &arg);
			getchar();
		}
		else
			arg = 'a';
		editor(cmd, arg, &cur, word);
	}

	for (int j = 0; j < strlen(word); j++)
		printf("%c", word[j]);

	return 0;
}
