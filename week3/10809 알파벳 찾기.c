#include <stdio.h>
#include <string.h>

int main(){
    char s[100];
    int ans[26];
    scanf("%s",s);

    for(int i=0;i<26;i++){
        ans[i] = -1;
    }

    for(int i = strlen(s);i>=0;i--){
        ans[s[i]-97]=i;
    }

    for(int i=0;i<26;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}