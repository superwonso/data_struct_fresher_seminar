#define MAX_N 100001 // 최대 정점 개수 (문제에서 N ≤ 100000)

// 전역 변수 선언
int N, M, R;        // 정점 수(N), 간선 수(M), 시작 정점(R)
int visited[MAX_N]; // 방문 순서 저장 배열
int order = 1;      // 방문 순서 카운트

// 그래프를 저장할 구조체 (배열 기반의 연결 리스트)
typedef struct
{
    int vertex[MAX_N]; // 연결된 정점 목록 (최대 MAX_N개의 노드를 저장)
    int size;          // 현재 정점에 연결된 노드 개수
} Graph;

Graph adj[MAX_N]; // 인접 리스트를 저장할 배열 (각 정점마다 연결된 리스트를 저장)

// 내림차순 정렬을 위한 비교 함수
int compare(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a); // 내림차순 정렬 (큰 값부터 방문하도록)
}

// DFS(깊이 우선 탐색) 함수
void dfs(int v)
{
    visited[v] = order++; // 현재 정점 방문 순서 저장

    // 연결된 정점을 내림차순으로 탐색
    for (int i = 0; i < adj[v].size; i++)
    {
        int next = adj[v].vertex[i]; // 다음 방문할 정점
        if (!visited[next])
        { // 방문하지 않은 정점이라면 탐색
            dfs(next);
        }
    }
}

int main()
{
    // 입력 받기: 정점 수 N, 간선 수 M, 시작 정점 R
    scanf("%d %d %d", &N, &M, &R);

    // 간선 정보 입력 받기 (양방향 그래프)
    for (int i = 0; i < M; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        // u와 v가 서로 연결됨 (양방향)
        adj[u].vertex[adj[u].size++] = v;
        adj[v].vertex[adj[v].size++] = u;
    }

    // 각 리스트를 내림차순 정렬 (큰 숫자부터 방문하기 위해)
    for (int i = 1; i <= N; i++)
    {
        qsort(adj[i].vertex, adj[i].size, sizeof(int), compare);
    }

    // DFS 실행 (시작 정점 R에서 탐색 시작)
    dfs(R);

    // 방문 순서 출력 (방문하지 않은 경우 0 출력)
    for (int i = 1; i <= N; i++)
    {
        printf("%d\n", visited[i]);
    }

    return 0; // 프로그램 종료
}