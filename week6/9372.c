#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1001

typedef struct node {
    int vertex;
    struct node* link;
} gnode;

typedef struct {
    gnode* head;
} adj;

adj graph[MAX];
bool visited[MAX];

void insertEdge(int a, int b) {
    gnode* new_a = (gnode*)malloc(sizeof(gnode));
    new_a->vertex = b;
    new_a->link = graph[a].head;
    graph[a].head = new_a;

    gnode* new_b = (gnode*)malloc(sizeof(gnode));
    new_b->vertex = a;
    new_b->link = graph[b].head;
    graph[b].head = new_b;
}

int bfs(int start, int n) {
    int queue[MAX], front = 0, rear = 0;
    int edges_used = 0;

    queue[rear++] = start;
    visited[start] = true;

    while (front < rear) {
        int node = queue[front++];
        gnode* temp = graph[node].head;

        while (temp) {
            int neighbor = temp->vertex;
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue[rear++] = neighbor;
                edges_used++;
            }
            temp = temp->link;
        }
    }

    return edges_used;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);

        for (int i = 1; i <= n; i++) {
            graph[i].head = NULL;
            visited[i] = false;
        }

        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            insertEdge(a, b);
        }

        printf("%d\n", bfs(1, n));

        for (int i = 1; i <= n; i++) {
            gnode* temp = graph[i].head;
            while (temp) {
                gnode* link = temp->link;
                free(temp);
                temp = link;
            }
            graph[i].head = NULL;
        }
    }

    return 0;
}
