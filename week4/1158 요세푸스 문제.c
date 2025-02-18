#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* link;
}node;

node* insert(int d,node *pre){
    node* tmp = (node*)malloc(sizeof(node));
    tmp->link = pre->link;
    pre->link = tmp;
    tmp->data = d;
    return tmp;
}

node* delete(node *pre, node *now){
    pre->link = now->link;
    free(now);
    return pre;
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);

    node* head = (node*)malloc(sizeof(node));
    head -> data = 1;
    head -> link = head;

    node *pre = head;
    for(int i=2;i<n+1;i++){
        pre = insert(i,pre);
    }

    printf("<");
    node *now = pre;
    for(int cnt= 0;cnt<n;cnt++){
        for (int i = 0;i<k;i++){
            pre = now;
            now = now->link;
        }
        printf("%d",now->data);
        now = delete(pre,now);
        if (cnt < n - 1) {printf(", ");}
    }
    printf(">");
    return 0;
}