#include <stdio.h>
#include <string.h>

int main()
{
    char str[600000]; // 문자열을 저장할 배열
    int cursor, M;

    // 초기 문자열 입력
    scanf("%s", str);

    // 현재 문자열 길이를 구하고, 커서를 맨 뒤로 이동
    cursor = strlen(str);

    // 입력할 명령어 개수 입력
    scanf("%d", &M);

    // 명령어 처리
    for (int i = 0; i < M; i++)
    {
        char command;
        scanf("%c", &command); // 명령어 입력

        if (command == 'L')
        {
            if (cursor > 0)
                cursor--; // 커서를 왼쪽으로 이동
        }
        else if (command == 'D')
        {
            if (cursor < strlen(str))
                cursor++; // 커서를 오른쪽으로 이동
        }
        else if (command == 'B')
        {
            if (cursor > 0)
            {
                // 문자 삭제 (왼쪽으로 한 칸 당김)
                for (int j = cursor - 1; j < strlen(str); j++)
                {
                    str[j] = str[j + 1];
                }
                cursor--; // 커서도 한 칸 왼쪽으로 이동
            }
        }
        else if (command == 'P')
        {
            char new_char;
            scanf(" %c", &new_char); // 삽입할 문자 입력

            // 문자 추가 (오른쪽으로 한 칸 이동 후 삽입)
            for (int j = strlen(str); j >= cursor; j--)
            {
                str[j + 1] = str[j]; // 기존 문자들을 오른쪽으로 이동
            }
            str[cursor] = new_char; // 새로운 문자 삽입
            cursor++;               // 커서를 오른쪽으로 이동
        }
    }
    printf("%s\n", str);

    return 0;
}