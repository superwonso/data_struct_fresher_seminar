#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* link;
}Node;

Node *insert(Node* head, int size) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = 1;
	head = node;
	head->link = head;

	for (int i = 2;i < size+1;i++) {
		Node* newnode = (Node*)malloc(sizeof(Node));
		newnode->data = i;

		newnode->link = head->link;
		head->link = newnode;
		head = newnode;
	}
	return head;
}

int count_list(Node* head) {
	Node* curr = head->link;
	int count = 1;
	while (curr != head) {
		curr = head->link;
		count++;
	}
}

Node* find_target(Node* temp, int k) {
	Node* target = temp;
	for (int i = 0;i < k -1 ;i++)
		target = target->link;
	return target;
}

int main() {
	Node* head = NULL;
	int n, k;
	scanf("%d %d", &n, &k);
	head=insert(head, n);

	Node* temp = head;
	while (head!=NULL) {
		Node* prev = find_target(temp, k);
		Node* target = prev->link;
		if (head == head->link && head == target) {
			printf("%d ", target->data);
			free(target);
			break;
		}
		else if (target == head)
			head = prev;
		prev->link = target->link;
		printf("%d ", target->data);
		free(target);
		temp = prev;

	}
	
}