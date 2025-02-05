#include <stdio.h>
#include <string.h>

int main(){
    char str[101];
    int alphabet[26];

    for (int i = 0; i < 26; i++){
        alphabet[i] = -1;
    }

    scanf("%s", str);
    for (int i = 0; str[i] != '\0'; i++){
        if (alphabet[str[i] - 'a'] == -1) alphabet[str[i] - 'a'] = i;
    }

    for (int i = 0; i < (sizeof(alphabet)/sizeof(int)); i++){
        printf("%d ", alphabet[i]);
    }

    return 0;
}
