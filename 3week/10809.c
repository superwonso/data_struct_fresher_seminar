#include<stdio.h>
#include<string.h>

int main(){
    char str[100];
    int index[26];

    for(int i=0;i<26;i++){
        index[i]=-1;
    }

    gets(str);

    for(int i=0;i<strlen(str);i++){
        if(index[str[i]-97]==-1)
            index[str[i]-97]=i;
    }

    for(int i=0;i<26;i++){
        printf("%d", index[i]);
        if(i<25) printf(" ");
    }
    return 0;
}
