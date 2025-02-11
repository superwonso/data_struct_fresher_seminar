#include stdio.h
#include string.h

int main(void)
{
	char word[100];
	int index[26] = { 0, };
	int ord = 0;

	for (int i = 0; i  26; i++)
		index[i] = -1;

	gets(word);

	for (int j = 0; j  strlen(word); j++) {
		ord = word[j];
		if (index[ord - 97] == -1)
			index[ord - 97] = j;
		else
			continue;
	}

	for (int k = 0; k  26; k++)
		printf(%d , index[k]);

	return 0;
}
