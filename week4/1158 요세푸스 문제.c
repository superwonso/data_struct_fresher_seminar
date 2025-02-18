#include <stdio.h>
typedef struct node{
    int data;
    node* link;
}node;

node* insert(int d,node *pre){
    node* tmp = (node*)malloc(sizeof(node));
    pre->link = tmp;
    tmp->data = d;
    tmp->link = pre;
    return tmp;
}


int main(){
    int n,k;
    scanf("%d %d",n,k);
    node* head = (node*)malloc(sizeof(node));
    head -> data = 1;
    head -> link = head;
    node *pre = head;
    for(int i=2;i<n+1;i++){
        pre = insert(i,pre);
    }
    


}