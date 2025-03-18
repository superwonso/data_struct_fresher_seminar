#include <stdio.h>
#include <stdlib.h>

#define MAX 100001

typedef struct node {
    int v;
    struct node* link;
} node;

typedef struct graph {
    int e;        
    int vis_cnt;  
    int vis[MAX];  
    node* arr[MAX];  
} graph;

void init(graph* g, int n) {
    g->e = n;
    g->vis_cnt = 1;
    for (int i = 1; i <= n; i++) {
        g->vis[i] = 0;
        g->arr[i] = NULL;
    }
}


void addEdge(graph* g, int u, int v) {
    node* new = (node*)malloc(sizeof(node));
    new->v = v;

    //내림차순 유지
    if (g->arr[u] == NULL || g->arr[u]->v < v) {
        new->link = g->arr[u];
        g->arr[u] = new;
    } else {
        node* cur = g->arr[u];
        while (cur->link != NULL && cur->link->v < v) {
            cur = cur->link;
        }
        new->link = cur->link;
        cur->link = new;
    }
}

// DFS 탐색
void dfs(graph* g, int r) {
    g->vis[r] = g->vis_cnt++; 

    node* cur = g->arr[r];
    while (cur != NULL) {
        if (!g->vis[cur->v]) {
            dfs(g, cur->v);
        }
        cur = cur->link;
    }
}

// 메모리 해제
void freeGraph(graph* g) {
    for (int i = 1; i <= g->e; i++) {
        node* cur = g->arr[i];
        while (cur != NULL) {
            node* temp = cur;
            cur = cur->link;
            free(temp);
        }
    }
    free(g);
}

int main() {
    int n, m, r;
    scanf("%d %d %d", &n, &m, &r);

    graph* g = (graph*)malloc(sizeof(graph));
    init(g, n);

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(g, u, v);
        addEdge(g, v, u);  
    }

    dfs(g, r);

    for (int i = 1; i <= n; i++) {
        printf("%d\n", g->vis[i]);
    }

    freeGraph(g);
    return 0;
}
