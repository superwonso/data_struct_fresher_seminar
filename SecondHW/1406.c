#include <stdio.h>
#include <stdlib.h>

#define MAX_length 100000

void editor(char cmd, char arg, int *cur, char *word) {
	switch (cmd) {
	case 'L':
		*cur -= 1;
		if (*cur < 0)
			*cur = 0;
		break;
	case 'D':
		*cur += 1;
		if (*cur > strlen(word)-1)
			*cur = strlen(word)-1;
		printf("%d", *cur);
		break;
	case 'B':
		for (int i = *cur - 1; i < (int)strlen(word); i++) {
			word[i] = word[i + 1];
		}
		break;
	}
}


int main()
{
	char word[MAX_length];
	fgets(word, MAX_length, stdin);

	int time;
	scanf("%d", &time);
	getchar();

	int cur = strlen(word)-1;

    char cmd, arg;
    for (int i = 0; i < time; i++) {
        scanf("%c", &cmd);

		if (cmd == 'P')
			scanf(" %c", &arg);
		else
			arg = 0;
		editor(cmd, arg, &cur, word);
    }

    return 0;
}
