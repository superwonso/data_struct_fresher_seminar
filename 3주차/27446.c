#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);

    int *arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        arr[i] = 0;
    }

    int tmp = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d", &tmp);
        arr[tmp-1] = 1;
    }
    
    for (int i = 0; i < n; i++) {
        printf("nums : %d ", arr[i]);
    }

    int ink_min = 0, cnt = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] == 0) {
            cnt++;
        } else if (arr[i] == 1 && arr[i+1] == 1) {
            ink_min += (2 * cnt) + 5;
            cnt = 0;
        }
    }

    printf("%d", ink_min);

    return 0;
}