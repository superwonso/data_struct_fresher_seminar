#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N;
    int K;
    scanf("%d %d", &N, &K);

    int *people = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
    {
        people[i] = i + 1; // 1부터 N까지 번호 저장
    }
    int index = 0; // 현재 위치
    int count = N; // 남은 사람 수

    printf("<");

    while (count > 0)
    {
        index = (index + K - 1) % count; // K-1인 이유는 index2가 세 번째 위치를 가리키고 있기 때문
        // K번째 사람을 찾기 위한 인덱스 계산
        printf("%d", people[index]); // 제거된 사람 출력
        if (count > 1)
            printf(", "); // count가 1이하면 마지막이니 뒤에 쉼표 안남기기

        for (int i = index; i < count - 1; i++)
        {
            people[i] = people[i + 1]; // 제거 후 한칸씩 앞으로 이동
        }
        count--; // 남은 사람 수 감소
    }
    printf(">\n");

    free(people);
    return 0;
}