#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int* page = (int*)calloc( n+1,sizeof(int));
	int* floor = (int*)malloc(sizeof(int) * m);
	for (int i = 0;i < m;i++) {
		scanf("%d", &floor[i]);
		page[floor[i]] = 1;
	}

	int* lostpage = (int*)malloc(sizeof(int) * (n + 1));
	int count = 0;
	for (int i = 1;i < n+1;i++) {
		if (page[i] == 0)
			lostpage[count++] = i;
	}
	int cost = 0, sp = 0;
	if (count == 0)
		printf("%d", cost);
	else {
		for (int i = 1;i < count;i++) {
			if (lostpage[i] - lostpage[i - 1] > 2) {
				cost += 5 + (lostpage[i - 1] - lostpage[sp] + 1) * 2;
				sp = i;
			}
		}
		cost += 5 + (lostpage[count - 1] - lostpage[sp] + 1) * 2;
		printf("%d", cost);
	}
	free(page);
	free(floor);
	free(lostpage);
	return 0;

}