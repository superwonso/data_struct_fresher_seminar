#include <stdio.h>
#include <stdlib.h> // 퀵정렬 사용하기 위한 라이브러리

#define MAXN 100001 // 정점의 최대 개수 (인덱스 1부터 사용하니까 100001)
#define MAXE 400000 // 간선의 최대 개수 (무방향이므로 2*M)

// 그래프의 간선을 나타내는 구조체
typedef struct {
    int from; // 시작 정점
    int to; // 도착 정점
} Edge;

Edge edges[MAXE]; //모든 간선을 저장할 배열
int start[MAXN + 1];      // 각 정점별 시작 인덱스를 저장하는 배열
int cnt[MAXN] = {0};      // 각 정점별 간선 개수
int visited[MAXN] = {0};  // 각 정점의 방문 순서 (미방문은 0)
int N, M, R; //정점의 수 N, 간선의 수 M, 시작 정점 R
int order = 0; 

// 같은 정점에서의 간선은 to 값이 큰 순(내림차순)으로 정렬
int cmp(const void *a, const void *b) {
    Edge *ea = (Edge *)a;
    Edge *eb = (Edge *)b;
    if (ea->from != eb->from) //from 값이 다르면 오른차순
        return ea->from - eb->from; 
    return eb->to - ea->to; // from 값이 같으면 내림차순
}

void dfs(int v) {
    // 재귀적으로 처리
    visited[v] = ++order;
    
    for (int i = start[v]; i < start[v + 1]; i++) {
        int nv = edges[i].to;
        if (!visited[nv])
            dfs(nv);
    }
}

int main() {
    scanf("%d %d %d", &N, &M, &R);
    int totalEdges = 0;
    
    // 에지 입력 처리 ================================ //
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        edges[totalEdges].from = u; edges[totalEdges].to = v; totalEdges++;
        edges[totalEdges].from = v; edges[totalEdges].to = u; totalEdges++;
        cnt[u]++;
        cnt[v]++;
    }
    // =============================================== //
    
    // 각 정점 별 시작 인덱스 계산 ================================ //
    start[1] = 0;
    for (int i = 2; i <= N + 1; i++) {
        start[i] = start[i - 1] + cnt[i - 1];
    }
    // ============================================================ //

    // 전체 배열을 퀵정렬
    qsort(edges, totalEdges, sizeof(Edge), cmp);
    
    // DFS 탐색 시작
    dfs(R);
    
    // 1번부터 N번까지 방문 순서 출력 (시작 정점에서 방문할 수 없는 정점은 0)
    for (int i = 1; i <= N; i++) {
        printf("%d\n", visited[i]);
    }
    return 0;
}