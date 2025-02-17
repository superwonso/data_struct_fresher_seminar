// 에디터
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100000

void insertchar(char* seq, char c2, int cursor) {
    if(cursor!=strlen(seq))
	    memmove(seq+cursor+1, seq+cursor, strlen(seq)-cursor+1);
    seq[cursor]=c2;
}
int main(){

    int N, cursor;
    char c1, c2;
    char *seq=(char*)malloc(sizeof(char)*MAX_SIZE);

    fgets(seq, MAX_SIZE, stdin);
    seq[strcspn(seq, "\n")] = '\0';

    cursor=strlen(seq);
    
    scanf("%d", &N);
    

    for(int i=0;i<N;i++){
        scanf(" %c", &c1);
        if(c1=='L'){
            if(cursor>0)
                cursor--;
        }
        else if(c1=='D'){
            if(cursor<strlen(seq))
                cursor++;
        }
        else if(c1=='B'){
            if(cursor>0){
                memmove(seq + cursor - 1, seq + cursor, strlen(seq) - cursor + 1);
                cursor--;
            }
        }
        else if(c1=='P'){
            scanf(" %c", &c2);
            insertchar(seq, c2, cursor);
            cursor++;
        }
    }

    printf("%s", seq);
    free(seq);
    return 0;
}