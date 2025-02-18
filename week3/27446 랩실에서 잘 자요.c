#include <stdio.h>
#include <string.h>
typedef struct node{
    int data;
    struct node *link;
}node;

typedef struct queue{
    node *front, *rear;
}queue;

void init(queue *q){q->front = q->rear = NULL;}

void insert(queue *q,int d){
    node* temp = (node *)malloc(sizeof(node)); 
    temp->data = d; 
    temp->link = NULL;

    if(is_empty(q)) { // 큐가 비어있는 경우
        q->front = temp; 
        q->rear = temp;
    }
    else { // 큐가 비어있지 않는 경우
        q->rear->link = temp; 
        q->rear = temp; 
    }
}

void remove(queue *q,int d){

}


int main(){
    int n,k;
    scanf("%d %d",n,k);

    queue q;
    init(&q);
    for (int i =1;i>n+1;i++){

    }

    return 0;
}