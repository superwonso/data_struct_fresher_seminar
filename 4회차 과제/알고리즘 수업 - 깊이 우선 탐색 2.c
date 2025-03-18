#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct GraphType {
    int n;
    Node** adj_list;
} GraphType;

int* visited;
int* ans;
int count = 1;

void init(GraphType* g, int n) {
    g->n = n;
    g->adj_list = (Node**)malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++) {
        g->adj_list[i] = NULL;
    }
    visited = (int*)calloc(n, sizeof(int));
    ans = (int*)calloc(n, sizeof(int));
}

void insert_edge(GraphType* g, int start, int end) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = end;

    // 내림차순 정렬 삽입
    Node** curr = &g->adj_list[start - 1];
    while (*curr && (*curr)->vertex > end) {
        curr = &(*curr)->next;
    }
    newNode->next = *curr;
    *curr = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = start;

    curr = &g->adj_list[end - 1];
    while (*curr && (*curr)->vertex > start) {
        curr = &(*curr)->next;
    }
    newNode->next = *curr;
    *curr = newNode;
}

void dfs(GraphType* g, int v) {
    ans[v - 1] = count++;
    visited[v - 1] = TRUE;

    Node* cur = g->adj_list[v - 1];
    while (cur) {
        if (!visited[cur->vertex - 1]) {
            dfs(g, cur->vertex);
        }
        cur = cur->next;
    }
}

void free_graph(GraphType* g) {
    for (int i = 0; i < g->n; i++) {
        Node* cur = g->adj_list[i];
        while (cur) {
            Node* temp = cur;
            cur = cur->next;
            free(temp);
        }
    }
    free(g->adj_list);
    free(visited);
    free(ans);
}

int main() {
    int n, m, r;
    scanf("%d %d %d", &n, &m, &r);

    GraphType g;
    init(&g, n);

    while (m--) {
        int a, b;
        scanf("%d %d", &a, &b);
        insert_edge(&g, a, b);
    }

    dfs(&g, r);

    for (int i = 0; i < n; i++) {
        printf("%d\n", ans[i] ? ans[i] : 0);
    }

    free_graph(&g);

    return 0;
}
