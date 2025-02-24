#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,tmp,top = 0, max = 0, idx = 0;
    scanf("%d",&n);

    int *stack = (int*)malloc(sizeof(int)*n);
    char * arr = (int*)malloc(sizeof(char)*(n*2));

    while(n--){
        scanf("%d",&tmp);
        while(max<tmp){
            stack[top++] = ++max;
            arr[idx++] = '+';
        }
    
        if (stack[top - 1] == tmp) {
            top--;
            arr[idx++] = '-';
        } 
        else {
            free(stack);
            free(arr);
            printf("NO");
            return 0;
        }
    }

    for (int i = 0; i < idx; i++) {
        printf("%c\n", arr[i]);
    }

    free(stack);
    free(arr);
    return 0;
}