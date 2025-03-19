#include<stdio.h>
#include <stdlib.h>

int N, M, R, count=0;
void dfs(int S,int *visited, int *answer, int **edges){
    count++;
    visited[S-1]=1;
    answer[S-1]=count;
    for(int i=N-1;i>=0;i--){
        if(edges[S-1][i]==1 && visited[i]==0)
            dfs(i+1, visited, answer, edges);
    }
};

int main(){
    scanf("%d %d %d", &N, &M, &R);
    int **edges = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        edges[i] = (int *)calloc(N, sizeof(int));  // 0으로 초기화
    }
    int *visited = (int *)calloc(N, sizeof(int));
    int *answer = (int *)calloc(N, sizeof(int));
    
    for(int i=0;i<M;i++){
        int edge1, edge2;
        scanf("%d %d", &edge1, &edge2);
        edges[edge1-1][edge2-1]=1;
        edges[edge2-1][edge1-1]=1;
    }

    dfs(R, visited, answer, edges);

    for(int i=0;i<N;i++){
        printf("%d\n", answer[i]);
    }
    return 0; 
}
