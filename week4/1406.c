#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char data;
	struct node* prev;
	struct node* next;
} node;

node* head, * tail, *cursor;

void create() {
	head = (node*)malloc(sizeof(node));
	tail = (node*)malloc(sizeof(node));
	head->prev = head;
	head->next = tail;
	tail->prev = head;
	tail->next = tail;
	cursor = head;
}

void left() {
	if (cursor != head) {
		cursor = cursor->prev;
	}
}

void right() {
	if (cursor != tail) {
		cursor = cursor->next;
	}
}

void delete() {
	if (cursor != head) {
		node* temp = cursor;
		cursor = cursor->prev;
		cursor->next = temp->next;
		temp->next->prev = cursor;
		free(temp);
	}
}

void insert(char c) {
	node* n = (node*)malloc(sizeof(node));
	n->data = c;
	n->prev = cursor;
	n->next = cursor->next;
	cursor->next->prev = n;
	cursor->next = n;
	cursor = n;
}

void alldelete() {
	node* d = head->next;
	while (d != tail) {
		node* t = d;
		d = d->next;
		free(t);
	}
	free(head);
	free(tail);
}

void print() {
	node* s = head->next;
	while (s != tail) {
		printf("%c", s->data);
		s = s->next;
	}
}

int main() {
	int M;
	char word;
	create();

	while ((word = getchar()) != '\n') {
		insert(word);
	}

	scanf("%d\n", &M);

	for (int i = 0; i < M; i++) {
		scanf("%c", &word);

		if (word == 'P') {
			scanf("%c", &word);
			insert(word);
		}
		else if (word == 'L') {
			left();
		}
		else if (word == 'D') {
			right();
		}
		else {
			delete();
		}
	}
	print();
	alldelete();
	return 0;
}