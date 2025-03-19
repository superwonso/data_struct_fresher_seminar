#include <stdio.h>

#define MAX_N 1000
#define MAX_M 10000

typedef struct {
    int u, v;
} Edge;

int parent[MAX_N + 1];

// Find 연산 (경로 압축 기법 적용)
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

// Union 연산 (집합 합치기)
void union_sets(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) parent[b] = a;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);

        // 유니온-파인드 초기화
        for (int i = 1; i <= N; i++) {
            parent[i] = i;
        }

        Edge edges[MAX_M];
        for (int i = 0; i < M; i++) {
            scanf("%d %d", &edges[i].u, &edges[i].v);
        }

        // Kruskal 알고리즘 수행
        int edge_count = 0;
        for (int i = 0; i < M; i++) {
            int u = edges[i].u;
            int v = edges[i].v;

            if (find(u) != find(v)) { // 서로 다른 집합이라면 연결
                union_sets(u, v);
                edge_count++;
            }
        }

        printf("%d\n", edge_count);
    }

    return 0;
}
