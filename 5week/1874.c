// 백준 스택 수열
#include<stdio.h>

int main(){
    int n, curr=1, s_top=1, c_top=1;
    scanf("%d", &n);

    int arr[n+1], stack[n+1];
    char cal[n*2];
    
    for(int i=1;i<n+1;i++) scanf("%d", &arr[i]);
    for(int i=1;i<n+1;i++){
        stack[s_top++]=i;
        cal[c_top++]='+';
    
        while((arr[curr]==stack[s_top-1])&&(s_top>0)){
            cal[c_top++]='-';
            curr++;
            s_top--;
        }

    }
    if(c_top==2*n+1){
        for(int i=0;i<n*2;i++)
            printf("%c\n", cal[i]);
    }
    else printf("NO\n");
    return 0;
}