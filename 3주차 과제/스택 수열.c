#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int stack[100000];
int top = -1;

bool IsFull() {
	if (top > 100000 - 1) return true;
	return false;
}
bool IsEmpty() {
	if (top < 0) return true;
	return false;
}
int pop() {
	if (IsEmpty()) return -999;
	return stack[top--];
}

bool push(int a) {
	if (IsFull()) return false;
	stack[++top] = a;
	return true;
}

int main() {
	int n, tep = 0;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	char* anser = (char*)malloc(sizeof(char) * n * 2);
	int anser_index = 0;
	for (int i = 0;i < n;i++) {
		scanf("%d", &arr[i]);
		while (arr[i] > tep) {
			if (!push(++tep)) {
				printf("NO");
				return 0;
			}
			anser[anser_index++] = '+';
		}
		if (pop() != arr[i]) {
			printf("NO");
			return 0;
		}
		else {
			anser[anser_index++] = '-';
		}


	}

	for (int i = 0;i < 2 * n;i++) {
		printf("%c\n", anser[i]);
	}
	free(arr);
	free(anser);
	return 0;
}


