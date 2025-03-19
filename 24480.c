#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define max_n 100001
#define false 0
#define true 1

// 그래프 노드 정의
typedef struct gnode {
    int vertex;
    struct gnode* link;
} gnode;

// 연결 리스트 스택 정의
typedef struct snode {
    int data;
    struct snode* link;
} snode;

// 스택 top 초기화
typedef struct {
    snode* top;
} stack;

void init(stack* s) {
    s->top = NULL;
}

// 그래프 구조 정의
gnode* graph[max_n];
int visited[max_n];
int order = 1;

// 스택에 원소 push
void push(stack* s, int value) {
    snode* new = (snode*)malloc(sizeof(snode));
    new->data = value;
    new->link = s->top;
    s->top = new;
}

// 스택에서 원소 pop
int pop(stack* s) {
    if (s->top == NULL) return -1;
    snode* temp = s->top;
    int delete = temp->data;
    s->top = temp->link;
    free(temp);
    return delete;
}

// 스택이 비었는지 확인
int isempty(stack* s) {
    return s->top == NULL;
}

// 그래프 엣지 삽입
void insertedge(int u, int v) {
    gnode* new = (gnode*)malloc(sizeof(gnode));
    new->vertex = v;
    new->link = graph[u];
    graph[u] = new;
}

int compare(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}

void sortlist(int n) {
    for (int i = 1; i <= n; i++) {
        int count = 0;
        gnode* temp = graph[i];
        int adj[100000];

        while (temp) {
            adj[count++] = temp->vertex;
            temp = temp->link;
        }

        qsort(adj, count, sizeof(int), compare);

        graph[i] = NULL;
        for (int j = 0; j < count; j++) {
            insertedge(i, adj[j]);
        }
    }
}

void dfs(int start) {
    stack s;
    init(&s);
    push(&s, start);

    while (!isempty(&s)) {
        int node = pop(&s);

        if (!visited[node]) {
            visited[node] = order++; 

            gnode* temp = graph[node];
            while (temp) {
                if (!visited[temp->vertex]) {
                    push(&s, temp->vertex);
                }
                temp = temp->link;
            }
        }
    }
}

int main() {
    int n, m, r;
    scanf("%d %d %d", &n, &m, &r);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        insertedge(u, v);
        insertedge(v, u);
    }

    sortlist(n);
    dfs(r);

    for (int i = 1; i <= n; i++) {
        printf("%d\n", visited[i]);
    }

    return 0;
}