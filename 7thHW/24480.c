#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

typedef struct {
    int size;
    int edges[MAX_N];
} Node;

Node graph[MAX_N + 1];
int order[MAX_N + 1]; // 방문 순서 저장
int visited[MAX_N + 1];
int count = 1;

// 정렬을 위한 비교 함수
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// DFS 탐색
void dfs(int node) {
    visited[node] = 1;
    order[node] = count++;
    
    // 작은 번호부터 방문하기 위해 정렬
    qsort(graph[node].edges, graph[node].size, sizeof(int), compare);
    
    for (int i = 0; i < graph[node].size; i++) {
        int next = graph[node].edges[i];
        if (!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    int N, M, R;
    scanf("%d %d %d", &N, &M, &R);
    
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        
        graph[u].edges[graph[u].size++] = v;
        graph[v].edges[graph[v].size++] = u;
    }
    
    dfs(R);
    
    for (int i = 1; i <= N; i++) {
        printf("%d\n", order[i]);
    }
    
    return 0;
}
