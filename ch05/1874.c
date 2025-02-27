#include <stdio.h>

#define STACK_SIZE 100000

int stack[STACK_SIZE];
int top = -1;

void push(int num) // push
{
    stack[++top] = num; // top을 증가(++top)시키고 stack[top]에 num을 저장하여 push 수행
}

void pop()
{
    if (top >= 0)
        top--; // top을 감소시켜 pop 수행
}

int main()
{
    int n, target, num = 1;
    // n: 입력받을 숫자의 개수
    // target: 만들어야 할 숫자
    // num = 1: 1부터 순차적으로 push할 숫자
    char result[STACK_SIZE * 2]; // 연산 결과(+,-) 저장 배열 (최대 2n)
    int res_idx = 0;             // result[]의 인덱스

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &target); // n개의 숫자를 하나씩 입력받아 target 변수에 저장

        while (num <= target) // 현재 num이 target보다 작거나 같으면
        {
            push(num++);             // push(num)을 수행 후 num 증가
            result[res_idx++] = '+'; // push할 때 +를 result[]에 저장
        }

        // pop 수행
        if (stack[top] == target) // stack top값이 target과 같으면
        {
            pop();                   // pop수행
            result[res_idx++] = '-'; // pop 연산 기록
        }
        else
        {
            printf("NO\n"); // 불가능한 경우 출력 후 종료
            return 0;
        }
    }

    // 연산 결과 출력
    for (int i = 0; i < res_idx; i++)
    {
        printf("%c\n", result[i]);
    }

    return 0;
}
