#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[100];
    int atz[26];
    scanf("%s", s);

    for (int i = 0; i < 26; i++)
    {
        atz[i] = -1;
    }

    int length = strlen(s);

    for (int i = 0; i < length; i++)
    {
        int index = s[i] - 'a';
        if (atz[index] == -1)
        {
            atz[index] = i;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        printf("%d ", atz[i]);
    }
    printf("\n");

    return 0;
}
