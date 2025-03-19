#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 100000
#define FALSE 0    
#define TRUE 1  


typedef struct graphNode {
	int vertex;						
	struct graphNode* link;	
} graphNode;


typedef struct graphType {
	int n;							
	graphNode* adjList_H[MAX_VERTEX];
	int visited[MAX_VERTEX];
} graphType;

typedef int element;		

typedef struct  stackNode {	
	element data;
	struct stackNode* link;
} stackNode;

stackNode* top;		

int isStackEmpty();
void push(element item);
element pop();
element peek();
void printStack();

void createGraph(graphType* g);
void insertVertex(graphType* g, int v);
void insertEdge(graphType* g, int u, int v);
void print_adjList(graphType* g);

void DFS_adjList(graphType* g, int v);


void createGraph(graphType* g) {
	int v;
	g->n = 0;							
	for (v = 0; v < MAX_VERTEX; v++) {
		g->adjList_H[v] = NULL;		
		g->visited[v] = FALSE;		
	}
}

void insertVertex(graphType* g, int v) {
	if (((g->n) + 1) > MAX_VERTEX) {
		return 0;
	}
	g->n++;							
}

void insertEdge(graphType* g, int u, int v) {
	graphNode* node;

	if (u >= g->n || v >= g->n) {
		return 0;
	}
	node = (graphNode*)malloc(sizeof(graphNode));
	node->vertex = v;
	node->link = g->adjList_H[u];
	g->adjList_H[u] = node;
}

void DFS_adjList(graphType* g, int v) {
	graphNode* w;
	top = NULL;				
	push(v);				
	g->visited[v] = TRUE;	
	printf("%d", v );

	while (!isStackEmpty()) {
		w = g->adjList_H[v];
		while (w) {
			if (!g->visited[w->vertex]) {
				push(w->vertex);				
				g->visited[w->vertex] = TRUE;
				printf(" %d", w->vertex );
				v = w->vertex;
				w = g->adjList_H[v];
			}
			else w = w->link;
		}
		v = pop();
	}
	printf(" 0");
}

int isStackEmpty() {
	if (top == NULL) return 1;
	else return 0;
}

void push(element item) {
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
	temp->data = item;
	temp->link = top;    
	top = temp;          
}

element pop() {
	element item;
	stackNode* temp = top;

	if (isStackEmpty()) {	
		return 0;
	}
	else {					
		item = temp->data;
		top = temp->link;
		free(temp);		
		return item;	
	}
}

element peek() {
	if (isStackEmpty()) {		
		return 0;
	}
	else {				
		return(top->data);
	}
}

int main(void) {
	graphType* G99;
	G99 = (graphType*)malloc(sizeof(graphType));
	createGraph(G99);
	
	
	int N, M, R;
	int u,v;
	scanf("%d %d %d", &N, &M, &R);
		for (int node = 1; node <= N; node++)
		insertVertex(G99, node);

	for(int j=0; j<M; j++)
	{
		scanf("%d %d", &u, &v);
		insertEdge(G99, u, v);
	}

	DFS_adjList(G99, R);  

	return 0;
}
