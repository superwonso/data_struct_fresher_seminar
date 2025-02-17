#include <stdio.h>
#include <stdlib.h>

void josephus(int data[], int N, int K) {
	int count = 0;
	int j = K - 1;
	int end = 0;
	printf("<%d", K);
	data[K - 1] = -1;

	for (int i = 0; i < N - 1; i++) {
		while (end<(N-1)) {
			if (data[j] == 0)
				count++;
			if (count == K) {
				printf(", %d", j + 1);
				end++;
				count = 0;
				data[j] = -1;
			}
			j++;
			if (j > N - 1)
				j = j % (N - 1) - 1;
		}
		for (int l = 0; l < N; l++) {
			if (data[l] == 0)
				printf(", %d", data[l]);
				
		}
	}
	printf(">");
}

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);

	int* data = (int*)calloc(N, sizeof(int));

	josephus(data, N, K);
}
