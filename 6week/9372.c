#include<stdio.h>

int main(){
    int T, N, M;
    scanf("%d", &T);

    for(int i=0;i<T;i++){
        scanf("%d %d", &N, &M);
        int flight[N+1][N+1];
        for(int j=0;j<M;j++){
            int a, b;
            scanf("%d %d", &a, &b);
            flight[a][b]=1;
            flight[b][a]=1;
        }
        printf("%d\n", (N-1));
    }
    return 0;
}