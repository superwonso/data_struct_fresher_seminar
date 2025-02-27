#include <stdio.h>
#include <stdlib.h>

// 큐의 최대 크기
#define MAX 50

// 원형 데크 구조체 정의
typedef struct
{
    int data[MAX];         // 원소 저장
    int front, rear, size; // 앞, 뒤, 크기
} Deque;

// 데크 초기화 함수
void initDeque(Deque *dq)
{
    dq->front = 0;
    dq->rear = 0;
    dq->size = 0;
}

// 원소를 큐 맨 뒤에 추가하는 함수.
void push_back(Deque *dq, int value)
{
    if (dq->size < MAX) // 큐가 가득 차지 않았을 때만 실행
    {
        dq->data[dq->rear] = value;      // 현재 rear 위치에 데이터 저장
        dq->rear = (dq->rear + 1) % MAX; // rear를 다음 위치로 이동 (원형 큐)
        dq->size++;                      // 큐 크기 증가
    }
}

// 원소를 큐 맨 앞에서 제거하는 함수
int pop_front(Deque *dq)
{
    if (dq->size > 0) // 큐가 비어있지 않으면 실행
    {
        int value = dq->data[dq->front];   // 현재 front 위치에 있는 데이터를 value에 저장
        dq->front = (dq->front + 1) % MAX; // front 를 다음 위치로 이동 (%MAX 사용해서 원형 큐 만들기)
        dq->size--;                        // 큐 크기 감소
        return value;                      // value 처리
    }
    return -1; // 큐가 비어있으면 오류 반환
}

// 특정 원소의 현재 큐에서 위치 찾기
int find_index(Deque *dq, int target)
{
    int index = 0;
    int pos = dq->front; // 큐의 맨 앞부터 탐색

    while (index < dq->size) // 큐 크기만큼 반복
    {
        if (dq->data[pos] == target) // 원소 찾으면
            return index;            // 위치 반환
        pos = (pos + 1) % MAX;       // 다음 위치로 이동( %MAX로 인한 원형 큐)
        index++;
    }
    return -1;
}

// 왼쪽으로 한 칸 이동
void rotate_left(Deque *dq)
{
    int temp = dq->data[dq->front];              // 맨 앞 원소를 temp에 저장
    dq->front = (dq->front + 1) % MAX;           // front를 오른쪽으로 이동
    dq->rear = (dq->rear + 1) % MAX;             // rear도 한 칸 이동
    dq->data[(dq->rear - 1 + MAX) % MAX] = temp; // 맨 앞 원소를 뒤로 보냄
}

// 오른쪽으로 한 칸 이동
void rotate_right(Deque *dq)
{
    dq->front = (dq->front - 1 + MAX) % MAX;              // front를 왼쪽으로 이동
    dq->rear = (dq->rear - 1 + MAX) % MAX;                // rear도 한칸 이동
    dq->data[dq->front] = dq->data[(dq->rear + 1) % MAX]; // 맨 뒤 원소를 앞으로 보냄
}

int main()
{
    int N, M, total_moves = 0; // N: 입력 받을 큐 크기, M: 제거할 원소 개수, total_moves: 총 이동 횟수 저장
    Deque dq;
    initDeque(&dq);

    // 입력 받기
    scanf("%d %d", &N, &M);
    int targets[M]; // 뽑아야 할 원소 위치

    for (int i = 0; i < M; i++)
    {
        scanf("%d", &targets[i]);
    }

    // 1부터 N까지 큐에 저장
    for (int i = 1; i <= N; i++)
    {
        push_back(&dq, i);
    }

    // 뽑아야 할 원소를 하나씩 처리
    for (int i = 0; i < M; i++)
    {
        int target = targets[i];
        int index = find_index(&dq, target); // 현재 원소 위치
        int left_moves = index;              // 왼쪽 이동 횟수
        int right_moves = dq.size - index;   // 오른쪽 이동 횟수

        // 더 적은 횟수로 이동
        if (left_moves <= right_moves) // 만약 왼쪽 이동이 오른쪽 이동보다 적다면
        {
            while (left_moves--) // 왼쪽 이동
            {
                rotate_left(&dq);
                total_moves++;
            }
        }
        else
        {
            while (right_moves--) // 아니면 오른쪽 이동
            {
                rotate_right(&dq);
                total_moves++;
            }
        }

        // 목표 원소 제거
        pop_front(&dq);
    }

    printf("%d\n", total_moves);
    return 0;
}
