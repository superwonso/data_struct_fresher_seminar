#include <stdio.h>

int main() {
    int T, N, M, a, b;
    
    // 테스트 케이스 개수 입력
    scanf("%d", &T);

    while (T--) {
        // 국가 수 N, 비행기 수 M 입력
        scanf("%d %d", &N, &M);

        // 비행기 정보 입력 (저장할 필요 없음)
        for (int i = 0; i < M; i++) {
            scanf("%d %d", &a, &b);
        }

        // 최소 비행기 개수(n-1)
        printf("%d\n", N - 1);
    }

    return 0;
}